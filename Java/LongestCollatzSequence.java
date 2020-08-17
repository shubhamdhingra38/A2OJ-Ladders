import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
public class LongestCollatzSequence {
    static int MAX = (int)1e6;
    static long getCollatz(long num, long[] dp){
        long res;
        if(num == 1){
            return 1;
        }
        if(num < MAX && dp[(int)num] != -1){
            return dp[(int)num];
        }
        if((num&1) == 1){//odd
            res =  2 + getCollatz((3*num+1)/2, dp);
            if (num < MAX) {
                dp[(int)num] = res;
            }
            return res;
        }
        else{
            res = 1 + getCollatz(num/2, dp);
            if(num < MAX){
                dp[(int)num] = res;
            }
            return res;
        }
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        long[] dp = new long[MAX];
        Arrays.fill(dp, -1);
        long mx = 0;
        long curr;
        long ans = 0;
        for(long i=1; i<=MAX; ++i){
            curr = getCollatz(i, dp);
            if(curr > mx){
                mx = curr;
                ans = i;
            }
        }
        System.out.println(ans);
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
