import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Random;

public class PentagonNumbers {
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

        int pentagonNumber(int x){
            return (x * (3*x-1))/2;
        }

        void solve() {
            int minD = Integer.MAX_VALUE;
            int i=3;
            ArrayList<Integer> arrList = new ArrayList<>();
            arrList.add(pentagonNumber(1));
            arrList.add(pentagonNumber(2));
            boolean flag = false;
            while (true){
                if(flag){
                    break;
                }
                int currPentagonNum = pentagonNumber(i);
                for(int j=0; j<i-1; ++j){
                    if(Collections.binarySearch(arrList, (arrList.get(j)+currPentagonNum)/2) >= 0 &&
                            Collections.binarySearch(arrList, (currPentagonNum-arrList.get(j))/2) >=0){
                        int res = Math.abs((arrList.get(j)+currPentagonNum)/2 - (currPentagonNum-arrList.get(j))/2);
                        if(res < minD){
                            minD = res;
                            flag = true;
                            break;
                        }
                    }
                }
                arrList.add(currPentagonNum);
                i++;
            }
            System.out.println(minD);
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
