import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LargestPalindrome {
    static boolean isPalindrome(long res){
        String r = Long.toString(res);
        for(int i=0; i<=r.length()/2; ++i){
            if(r.charAt(i) != r.charAt(r.length()-i-1)){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        long res;
        long ans = -1;
        for(int i=100; i<= 999; ++i){
            for(int j=100; j<= 999; ++j){
                res = i*j;
                if(isPalindrome(res)){
                    ans = Math.max(ans, res);
                }
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
