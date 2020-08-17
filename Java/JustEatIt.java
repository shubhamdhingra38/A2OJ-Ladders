import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Random;

public class JustEatIt {
    public static void main(String[] args) {
        long timeStart = System.nanoTime();
        Utility.FastReader fr = new Utility.FastReader();
        Solver solver = new Solver(fr);
        int t = fr.nextInt();
        while (t-- > 0) {
            solver.solve();
        }
        long timeEnd = System.nanoTime();
//        System.out.println("Completed in :" + ((double) (timeEnd - timeStart) / 1000000) + " miliseconds");
    }

    static class Solver {
        Utility.FastReader fr;

        public Solver(Utility.FastReader fr) {
            this.fr = fr;
        }

        static long maxSubarraySum(int[] arr){
            long best=Long.MIN_VALUE;
            long curr=0;
            int start, end;
            start = end = 0;
            int s;
            s = 0;
            for(int i=0; i<arr.length; ++i){
                curr+=arr[i];
                if(curr > best){
                    best=Math.max(best, curr);
                    start = s;
                    end = i;
                }
                if(curr < 0){
                    curr = 0;
                    s = i+1;
                }
            }
//            System.out.println("start " + start + " end " + end);
            int sizeOfResult = end - start + 1;
//            System.out.println(sizeOfResult);
            if(sizeOfResult==arr.length)
                return -1;
            return best;
        }

        void solve() {
            int n=fr.nextInt();
            int[] arr=new int[n];
            for(int i=0; i<n; ++i) arr[i]=fr.nextInt();
            long sum=0;
            for(int x: arr) sum+=x;
            int[] reverse=new int[n];
            for(int i=n-1; i>=0; --i) reverse[i]=arr[n-i-1];
            if(maxSubarraySum(arr)<sum&&maxSubarraySum(reverse)<sum)
                System.out.println("YES");
            else
                System.out.println("NO");
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
