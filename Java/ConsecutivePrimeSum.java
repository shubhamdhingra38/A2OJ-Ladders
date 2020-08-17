import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class ConsecutivePrimeSum {
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
        static ArrayList<Long> primes = new ArrayList<>();

        public Solver(Utility.FastReader fr) {
            this.fr = fr;
        }

        static boolean isPrime(long num){
            for(long i=2; i*i<=num; ++i){
                if(num%i == 0){
                    return false;
                }
            }
            return true;
        }

        static void getPrimes(long n){
            boolean[] isComposite = new boolean[(int)n];
            for(long i=2; i<n; i++){
                if(!isComposite[(int)i]){
                    primes.add(i);
                    for(long j=i*i; j<n; j+=i){
                        isComposite[(int)j] = true;
                    }
                }
            }

        }

        void solve() {
            getPrimes(1000000);
            long[] preSum = new long[primes.size()];
            preSum[0] = 2;
            int cnt = 0;
            for(int i=1; i<primes.size(); ++i){
                preSum[i] = primes.get(i) + preSum[i-1];
                if(preSum[i] > 1000000){
                    break;
                }
                cnt++;
            }
            long res = 0;
            for(int i=cnt; i>=0; --i){
                if(preSum[i] < 1000000 && Collections.binarySearch(primes, preSum[i]) >= 0){
                    res = Math.max(res, preSum[i]);
                }
                for(int j=0; j<cnt; ++j){
                    if(preSum[i]-preSum[j] < 1000000 && Collections.binarySearch(primes, preSum[i]-preSum[j]) >= 0){
                        res = Math.max(res, preSum[i]-preSum[j]);
                    }
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
