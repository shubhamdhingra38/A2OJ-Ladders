import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Random;

public class DigitCancellingFractions {
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

        void solve() {
            int num = 1, denom = 1;
            int g, x, y;
            int a, b, c, d;
            int cnt = 0;
            for(int i=10; i<=99; ++i){
                for(int j=10; j<i; ++j){
                    // j/i
                    g = Utility.gcd(i, j);
                    x = j/g;
                    y = i/g;
                    a = j/10;
                    b = j%10;
                    c = i/10;
                    d = i%10;
//                    System.out.println(j + " " + i + " " + a + " " + b + " " + c + " " + d);
                    g = Utility.gcd(a, c);
                    try{
                        if(b == d && b != 0 && a/g == x && c/g == y){
                            System.out.println(i + " " + j);
                            num *= j;
                            denom *= i;
                            cnt++;
                        }
                        else if(b == c && a/Utility.gcd(a, d) == x && d/Utility.gcd(a, d) == y){
                            System.out.println(i + " " + j);
                            num *= j;
                            denom *= i;
                            cnt++;
                        }
                        else if(a == d && b/Utility.gcd(b, c) == x && c/Utility.gcd(b, c) == y){
                            System.out.println(i + " " + j);
                            num *= j;
                            denom *= i;
                            cnt++;
                        }
                        else if(a == c && b != 0 && d != 0 && b/Utility.gcd(b, d) == x && d/Utility.gcd(b, d) == y){
                            num *= j;
                            denom *= i;
                            cnt++;
                        }
                    }
                    catch(ArithmeticException e){
                        System.err.println("Division by zero");
                        e.printStackTrace();
                    }
                }
            }
            System.out.println(num + " " + denom);
            System.out.println(denom/Utility.gcd(num, denom));
            System.out.println(cnt);
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
