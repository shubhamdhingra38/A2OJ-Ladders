import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Round85C {
    static int MAX = (int)3e5 + 5;
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int t = fr.nextInt();
        int n;
        long[] health = new long[MAX];
        long[] explosion = new long[MAX];
        StringBuilder answer = new StringBuilder("");
        while(t-- > 0){
            n = fr.nextInt();
            for(int i=0; i<n; ++i){
                health[i] = fr.nextLong();
                explosion[i] = fr.nextLong();
            }
            if(n == 1){
                answer.append(health[0]+"\n");
            }
            else{
                ArrayList<Integer> arrList = new ArrayList<>();
                if(health[0] > explosion[n-1]){
                    arrList.add(0);
                }
                for(int i=1; i<n; ++i){
                    if(health[i] > explosion[i-1]){
                        arrList.add(i);
                    }
                }
                long[] arr = new long[arrList.size()];
                if(arrList.size() == 0){
                    long result = health[0];
                    long extra = Math.max(0, health[0] - explosion[n-1]);
                    for(int i=1; i<n; ++i){
                        result = Math.min(result, health[i] + extra);
                    }
                    answer.append(result+"\n");
                }
                else{
                    if(arrList.get(0) == 0){
                        arr[0] = health[0] - explosion[n-1];
                        for(int i=1; i<arrList.size(); ++i){
                            arr[i] = health[arrList.get(i)] - explosion[arrList.get(i)-1];
                        }
                    }
                    else{
                        for(int i=0; i<arrList.size(); ++i){
                            arr[i] = health[arrList.get(i)] - explosion[arrList.get(i)-1];
                        }
                    }
                    long totalSum = 0;
                    for(int i=0; i<arrList.size(); ++i){
                        totalSum += arr[i];
                    }
                    long result = Long.MAX_VALUE;
                    int t1, t2;
                    for(int i=0; i<n; ++i){
                        int idx = Collections.binarySearch(arrList, i);
                        if(idx >= 0){
                            result = Math.min(result, health[i] + totalSum - arr[idx]);
                        }
                        else{
                            result = Math.min(result, health[i] + totalSum);
                        }
                    }
                    answer.append(result+"\n");
                }
            }
        }
        System.out.println(answer);
    }

    static class Utility {
        static class FastReader {
            BufferedReader br;
            StringTokenizer st;

            public FastReader() {
                br = new BufferedReader(new
                        InputStreamReader(System.in));
            }

            String next() {
                while (st == null || !st.hasMoreElements()) {
                    try {
                        st = new StringTokenizer(br.readLine());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return st.nextToken();
            }

            int nextInt() {
                return Integer.parseInt(next());
            }

            long nextLong() {
                return Long.parseLong(next());
            }

            double nextDouble() {
                return Double.parseDouble(next());
            }

            String nextLine() {
                String str = "";
                try {
                    str = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return str;
            }
        }

        public static void main(String[] args) {
            FastReader s = new FastReader();
            int n = s.nextInt();
            int k = s.nextInt();
            int count = 0;
            while (n-- > 0) {
                int x = s.nextInt();
                if (x % k == 0)
                    count++;
            }
            System.out.println(count);
        }
    }
}
