import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class NonAbundantSums {
    static int getSumOfProperDivisors(int num){
        int res = 0;
        for(int i=2; i*i <= num; ++i){
            if(num%i == 0){
                if(i != num){
                    res += i;
                }
                if(num/i != num && i != num/i){
                    res += num/i;
                }
            }
        }
        return res + 1;
    }

    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        ArrayList<Integer> listAbundant = new ArrayList<>();
        int d, x;
        for(int i=1; i<=28123; ++i){
            d = getSumOfProperDivisors(i);
            if(d > i){
                listAbundant.add(i);
            }
        }
        long result = 0;
        boolean flag;
//        System.out.println(listAbundant.toString());
        for(int i=1; i<=28123; ++i){
            flag = false;
            for(int j=0; j<listAbundant.size(); ++j){
                x = i - listAbundant.get(j);
                if(Collections.binarySearch(listAbundant, x) >= 0){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                result += i;
            }
        }
        System.out.println(result);
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
