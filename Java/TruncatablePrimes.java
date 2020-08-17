import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Random;

public class TruncatablePrimes {
    public static void main(String[] args) {
        long timeStart = System.nanoTime();
        Utility.FastReader fr = new Utility.FastReader();
        Solver solver = new Solver(fr);
        int t = 1;
        while (t-- > 0) {
            solver.solve();
        }
        long timeEnd = System.nanoTime();
        System.out.println("Completed in :" + ((double) (timeEnd - timeStart) / 1000000) + " miliseconds");
    }

    static class Solver {
        Utility.FastReader fr;

        public Solver(Utility.FastReader fr) {
            this.fr = fr;
        }

        static boolean isPrime(int num){
            if(num == 1){
                return false;
            }
            for(int i=2; i*i <= num; ++i){
                if(num%i == 0){
                    return false;
                }
            }
            return  true;
        }
        static boolean isTruncPrime(int num){
            StringBuilder s = new StringBuilder(Integer.toString(num));
            int n;
            for(int i=0; i<s.length(); ++i){
                n = Integer.parseInt(s.substring(0, s.length()-i));
                if(!isPrime(n)){
                    return false;
                }
            }
            for(int i=0; i<s.length(); ++i){
                n = Integer.parseInt(s.substring(i, s.length()));
                if(!isPrime(n)){
                    return false;
                }
            }
            return true;
        }
        void solve() {
            int cnt = 0;
            long res = 0;
            for(int i=11; i<=1000_000_000; ++i){
                if(isTruncPrime(i)){
                    cnt++;
                    res += i;
                }
                if(cnt >= 11){
                    break;
                }
            }
            System.out.println(res);
        }
    }

    static class Utility {
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
