import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class AmicableNumbers {
    static int getSumOfProperDivisors(int num){
        int res = 0;
        for(int i=2; i*i <= num; ++i){
            if(num%i == 0){
                if(i != num){
                    res += i;
                }
                if(num/i != num){
                    res += num/i;
                }
            }
        }
        return res + 1;
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        HashMap<Integer, ArrayList<Integer>> hmap = new HashMap<>();
        int x;
        int amicableSum = 0;
        for(int i=2; i <= 10000; ++i){
            x = getSumOfProperDivisors(i);
//            System.out.println(i + " has sum of divisors " + x);
            if(x > i){
                if(hmap.containsKey(x)){
                    hmap.get(x).add(i);
                }
                else{
                    ArrayList<Integer> arrList = new ArrayList<>();
                    arrList.add(i);
                    hmap.put(x, arrList);
                }
            }
            else{
                if(hmap.containsKey(i)){
                    if(hmap.get(i).contains(x)){
                        amicableSum += i + x;
                    }
                }
            }
        }
        System.out.println(amicableSum);
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
