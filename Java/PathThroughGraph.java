import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class PathThroughGraph {
    public static void main(String[] args) {
        long timeStart = System.nanoTime();
        Utility.FastReader fr = new Utility.FastReader();
        Solver solver = new Solver(fr);
        int t = 1;
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

        long largestFactor(long num){
            long mx = 1;
            for(long i=2; i*i<=num; ++i){
                if(num%i == 0){
                    mx = Math.max(mx, i);
                    mx = Math.max(mx, num/i);
                }
            }
            return mx;
        }

        void solve() {
            long M=fr.nextInt(); long N=fr.nextInt();
            if(M==N) {
                System.out.println(0);
            }
            else{
                int c1 = 0;
                int c2 = 0;
                long m, n;
                m = Math.max(M, N);
                n = Math.min(M, N);
                HashMap<Long, Boolean> hmap = new HashMap<>();
                ArrayList<Long> path = new ArrayList<>();
                while(true) {
                    long x = largestFactor(m);
//                    System.out.println("largest fac " + x);
                    hmap.put(x, true);
                    path.add(x);
                    if(x == 1) break;
                    m = x;
                }
//                System.out.println(Arrays.toString(path.toArray()));
                long last = 1;
                long x = n;
                while(true){
                    if(hmap.getOrDefault(x, false)){
                        last = x;
                        break;
                    }
                    c2++;
                    x = largestFactor(x);
                    if(x == 1) break;
                    n = x;
                }

//                System.out.println("last is " + last);
                for(long y: path){
                    c1++;
                    if(y==last) break;
                }
//                System.out.println("c1 is " + c1);
//                System.out.println("c2 is " + c2);
                System.out.println(c1 + c2);
            }
        }
    }

    static class Utility {
        static void sort(int[] a) {
            ArrayList<Integer> list = new ArrayList<>();
            for (int i : a) list.add(i);
            Collections.sort(list);
            for (int i = 0; i < a.length; i++) a[i] = list.get(i);
        }

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

