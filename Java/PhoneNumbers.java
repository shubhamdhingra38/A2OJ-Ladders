import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class PhoneNumbers {
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
        static HashMap<String, HashSet<String>> m;
        public Solver(Utility.FastReader fr) {
            this.fr = fr;
            m = new HashMap<>();
        }

        void solve() {
            int n=fr.nextInt();
            for(int i=0; i<n; ++i){
                String name; int cnt;
                ArrayList<String> arrList = new ArrayList<>();
                name=fr.next();
                cnt=fr.nextInt();
                for(int j=0; j<cnt; ++j){
                    String x=fr.next();
                    arrList.add(x);
                }
                if(m.get(name) == null)
                    m.put(name, new HashSet<>());
                HashSet<String> org = m.get(name);
                for(String x: arrList){
                    org.add(x);
                }
            }
            System.out.println(m.size());
            for(String s: m.keySet()){
                HashSet<String> set = m.get(s);
                String[] arr = new String[set.size()];
                set.toArray(arr);
                HashMap<String, Boolean> h = new HashMap<>();
                ArrayList<String> result = new ArrayList<>();
                for(int i=0; i<arr.length; ++i){
                    boolean flag = false;
                    for(int j=0; j<arr.length; ++j) {
                        if (i == j) {
                            continue;
                        }
                        if (arr[j].endsWith(arr[i])) {
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        if(!h.getOrDefault(arr[i], false)){
                            h.put(arr[i], true);
                            result.add(arr[i]);
                        }
                    }
                }
                System.out.print(s + " ");
                System.out.print(result.size() + " ");
                for(String x: result){
                    System.out.print(x + " ");
                }
                System.out.println();
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
