import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Random;
import java.util.Arrays;

public class PrimePermutations {
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
            for(int i=2; i*i<=num; ++i){
                if(num%i == 0){
                    return false;
                }
            }
            return true;
        }

        static boolean isPermutation(int a, int b, int c){
            int[] arr = new int[10];
            Arrays.fill(arr, 0);
            String s1 = Integer.toString(a);
            String s2 = Integer.toString(b);
            String s3 = Integer.toString(c);
            for(int i=0; i<4; ++i){
                arr[s1.charAt(i)-'0'] += 1;
            }
            int[] arr2 = new int[10];
            int[] arr3 = new int[10];
            Arrays.fill(arr2, 0);
            Arrays.fill(arr3, 0);
            for(int i=0; i<4; ++i){
                arr2[s2.charAt(i)-'0'] += 1;
            }
            for(int i=0; i<4; ++i){
                if(arr[s2.charAt(i)-'0'] != arr2[s2.charAt(i)-'0']){
                    return false;
                }
            }
            for(int i=0; i<4; ++i){
                arr3[s3.charAt(i)-'0'] += 1;
            }
            for(int i=0; i<4; ++i){
                if(arr[s3.charAt(i)-'0'] != arr3[s3.charAt(i)-'0']){
                    return false;
                }
            }
            return true;
        }

        void solve() {
            for(int i=1000; i<10000; ++i){
                for(int j=1; j<10000; ++j){
                    int a, b, c;
                    a = i; b = i+j; c = i+2*j;
                    if(c >= 10000){
                        break;
                    }
                    if(isPrime(a) && isPrime(b) && isPrime(c) && isPermutation(a, b, c)){
                        System.out.println(a + " : " + b  + " : " + c);
                    }
                }
            }
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
