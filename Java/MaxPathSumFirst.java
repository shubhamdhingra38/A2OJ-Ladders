import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class MaxPathSumFirst {
    static int max = 100;
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int tot = (max*(max+1))/2;
        int[] nums = new int[tot];
        for(int i=0; i<tot; ++i){
            nums[i] = fr.nextInt();
        }
        int[][] dp = new int[max][max+1];
        int a, b, idx;
        dp[0][1] = nums[0];
        for(int i=1; i<max; ++i){
            idx = (i*(i+1))/2;
            for(int j=1; j<=i+1; ++j){
                a = nums[idx + j - 1];
//                System.out.println(a);
                if(j==1){
                    dp[i][j] = a + dp[i-1][j];
                }
                else if(j==i+1){
                    dp[i][j] = a + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = a + Math.max(dp[i-1][j], dp[i-1][j-1]);
                }
            }
            System.out.println(Arrays.toString(dp[i]));
        }
        int mx = 0;
        for(int i=1; i<max; ++i){
            mx = Math.max(mx, dp[max-1][i]);
        }
        System.out.println(mx);
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
