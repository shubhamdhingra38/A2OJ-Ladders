import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class TilePainting {
    static long gcd(long a, long b){
        if(a==0){
            return b;
        }
        else{
            return gcd(b%a, a);
        }
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        long n = fr.nextLong();
        long g = 0;
        boolean flag = false;
        for(long i=2; i*i<=n; ++i){
            if(n%i == 0){
                g = gcd(g, n/i);
                g = gcd(g, i);
                flag = true;
                if(g==1){
                    break;
                }
            }
        }
        if(!flag){
            System.out.println(n);
        }
        else{
            System.out.println(g);
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
