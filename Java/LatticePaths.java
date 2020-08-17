import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LatticePaths {
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int m, n;
        m = n = 20;
        m += 1;
        n += 1;
        long[][] dp = new long[m][n];
        dp[0][0] = 1;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                dp[i][j] += (i-1>=0)?dp[i-1][j]:0;
                dp[i][j] += (j-1>=0)?dp[i][j-1]:0;
            }
        }
        System.out.println(dp[m-1][n-1]);
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
