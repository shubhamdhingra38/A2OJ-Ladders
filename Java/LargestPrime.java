import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LargestPrime {
    static long res = -1;
    static boolean isPrime(long num){
        for(long i=2; i*i<=num; ++i){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    static void findPrime(long num){
        for(long i=2; i*i<=num; i++){
            if(num%i == 0){
                if(isPrime(num/i)){
                    res = Math.max(res, num/i);
                }
                if(isPrime(i)){
                    res = Math.max(res, i);
                }
            }
        }
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        long num = 600851475143L;
        findPrime(num);
        System.out.println(res);
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
