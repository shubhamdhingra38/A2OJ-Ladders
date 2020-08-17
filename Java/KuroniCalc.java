import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KuroniCalc {
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int n = fr.nextInt(); int m = fr.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; ++i){
            arr[i] = fr.nextInt();
        }
        if(n > m){
            //pigeonhole principle
            //two will have same remainder
            //|a-b|%m = |a%m-b%m|
            //result 0
            System.out.println(0);
        }
        else{
            long res = 1;
            for(int i=0; i<n; ++i){
                for(int j=i+1; j<n; ++j){
                    res *= Math.abs(arr[j]-arr[i]) % m;
                    res %= m;
                }
            }
            res %= m;
            System.out.println(res);
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
