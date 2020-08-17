import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SmallestMultiple {
    static Integer[] primeFactors;
    static void generatePrimeFactors(int num){
        int i = 2;
        int[] localFactors = new int[20];
        while(num > 2){
            if(num%i == 0){
                localFactors[i] += 1;
                num /= i;
            }
            else{
                i += 1;
            }
        }
        if(num == 2){
            localFactors[i] += 1;
        }
        for(i=0; i<20; ++i){
            if(primeFactors[i] < localFactors[i]){
                primeFactors[i] = localFactors[i];
            }
        }
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        primeFactors = new Integer[20];
        Arrays.fill(primeFactors, 0);
        int n = 20;
        for(int i=2; i<=20; ++i){
            generatePrimeFactors(i);
        }
//        Utility.printArray(primeFactors);
        long res = 1;
        for(int i=0; i<20; ++i){
            if(primeFactors[i] != 0){
                res *= Math.pow(i, primeFactors[i]);
            }
        }
        System.out.println(res);
    }

    static class Utility {
        static <T> void printArray(T[] arr){
            System.out.println(Arrays.toString(arr));
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
