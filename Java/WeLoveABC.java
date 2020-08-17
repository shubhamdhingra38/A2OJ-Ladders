import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class WeLoveABC {
    public static void main(String[] args) {
        long timeStart = System.nanoTime();
        Utility.FastReader fr = new Utility.FastReader();
        Solver solver = new Solver(fr);
        int t = 1;
        while (t-- > 0) {
            solver.solve();
        }
        long timeEnd = System.nanoTime();
//        System.out.println("Completed in :" + ((double) (timeEnd - timeStart) / 1000000) + " miliseconds");
    }

    static class Solver {
        Utility.FastReader fr;
        static int MOD = (int)1e9 + 7;
        public Solver(Utility.FastReader fr) {
            this.fr = fr;
        }

        void solve() {
            String s = fr.next();
            long[][] dp = new long[s.length() + 1][4];
            //A, AB, ABC
            /*
                when A comes it doesn't contribute just 1, but the number of substrings before it
                if there were Q question marks then 3^Q it contributes
                for ex.
                ??A -> possible
                AAA
                ABA
                BBA
                BAA
                ACA
                CAA
                BCA
                CCA
                CBA
                last A would be actually 3*3 + number of previous A's
             */
            dp[0][3] = 1;
            for(int i=1; i<=s.length(); ++i){
                if(s.charAt(i-1)!='?'){
                    for(int j=0; j<4; ++j) dp[i][j] = dp[i-1][j];
                    if(s.charAt(i-1)=='A'){
                        dp[i][0] += dp[i-1][3];
                        if(dp[i][0] >= MOD) dp[i][0] -= MOD;
                    }
                    else if(s.charAt(i-1)=='B'){
                        dp[i][1] += dp[i-1][0];
                        if(dp[i][1] >= MOD) dp[i][1] -= MOD;
                    }
                    else if(s.charAt(i-1)=='C'){
                        dp[i][2] += dp[i-1][1];
                        if(dp[i][2] >= MOD) dp[i][2] -= MOD;
                    }
                }
                else{
                    dp[i][3] = dp[i-1][3]*3 % MOD;
                    dp[i][0] = dp[i-1][3] + (3*dp[i-1][0]) % MOD;
                    dp[i][1] = dp[i-1][0] + (3*dp[i-1][1]) % MOD;
                    dp[i][2] = dp[i-1][1] + (3*dp[i-1][2]) % MOD;
                    if(dp[i][0] >= MOD) dp[i][0] -= MOD;
                    if(dp[i][1] >= MOD) dp[i][1] -= MOD;
                    if(dp[i][2] >= MOD) dp[i][2] -= MOD;
                    if(dp[i][3] >= MOD) dp[i][3] -= MOD;
                }

            }
            System.out.println(dp[s.length()][2] % MOD);
        }
    }

    static class Utility {
        static void sort(int[] a) {
            ArrayList<Integer> list = new ArrayList<>();
            for (int i : a) list.add(i);
            Collections.sort(list);
            for (int i = 0; i < a.length; i++) a[i] = list.get(i);
        }

        static void shuffleArray(long[] arr) {
            int n = arr.length;
            Random rnd = new Random();
            for (int i = 0; i < n; ++i) {
                long tmp = arr[i];
                int randomPos = i + rnd.nextInt(n - i);
                arr[i] = arr[randomPos];
                arr[randomPos] = tmp;
            }
        }

        static void shuffleArray(int[] arr) {
            int n = arr.length;
            Random rnd = new Random();
            for (int i = 0; i < n; ++i) {
                int tmp = arr[i];
                int randomPos = i + rnd.nextInt(n - i);
                arr[i] = arr[randomPos];
                arr[randomPos] = tmp;
            }
        }

        static int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        static long gcd(long a, long b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

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
    }
}

