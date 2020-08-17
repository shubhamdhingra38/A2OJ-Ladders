import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Round85B {
    static int MAX = (int)1e5 + 5;
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int t = fr.nextInt();
        int n, x;
        while(t-- > 0){
            n = fr.nextInt();
            x = fr.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<n; ++i){
                arr[i] = fr.nextInt();
            }
            Arrays.sort(arr);
            int result = 0;
            long curr_sum = 0;
            int cnt = 0;
            for(int i=n-1; i>=0; --i){
                cnt++;
                curr_sum += arr[i];
                if(arr[i] >= x){
                    result++;
                }
                else{
                    if((double)curr_sum/cnt >= (double)x){
                        result++;
                    }
                    else{
                        break;
                    }
                }
            }
            System.out.println(result);
        }
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
