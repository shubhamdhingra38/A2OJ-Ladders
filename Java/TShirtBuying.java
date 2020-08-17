import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class TShirtBuying {
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
    static class Shirt {
        int price, c1, c2;
        public Shirt(int price, int c1, int c2){
            this.price=price;
            this.c1=c1;
            this.c2=c2;
        }

        @Override
        public int hashCode() {
            return 31 * price + 7 * c1 + c2;
        }
    }
    static class ShirtComparator implements Comparator<Shirt> {

        @Override
        public int compare(Shirt o1, Shirt o2) {
            return o1.price - o2.price;
        }
    }
    static class Solver {
        Utility.FastReader fr;

        public Solver(Utility.FastReader fr) {
            this.fr = fr;
        }

        void solve() {
            int n = fr.nextInt();
            int p, a, b;
            Shirt[] shirts = new Shirt[n];
            for(int i=0; i<n; ++i){
                p=fr.nextInt();
                shirts[i]=new Shirt(p, 0, 0);
            }
            for(int i=0; i<n; ++i){
                a=fr.nextInt();
                shirts[i].c1=a;
            }
            for(int i=0; i<n; ++i){
                b=fr.nextInt();
                shirts[i].c2=b;
            }
            int nCustomers = fr.nextInt();
            int[] favColors = new int[nCustomers];
            for(int i=0; i<nCustomers; ++i) favColors[i] = fr.nextInt();
            int[] result = new int[nCustomers];

            HashMap<Integer, PriorityQueue<Shirt>> h = new HashMap();
            HashMap<Shirt, Boolean> used = new HashMap<>();
            for(Shirt s: shirts){
                used.put(s, false);
            }
            for(int i=1; i<=3; ++i)
                h.put(i, new PriorityQueue<Shirt>(new ShirtComparator()));

            for(Shirt s: shirts){
                int c1, c2;
                c1=s.c1; c2=s.c2;
                PriorityQueue<Shirt> p1, p2;
                p1=h.get(c1);
                p2=h.get(c2);
                p1.add(s);
                p2.add(s);
            }
            for(int i=0; i<nCustomers; ++i){
                int x=favColors[i];
                PriorityQueue<Shirt> pq = h.get(x);
                if(pq.size()==0)
                    result[i]=-1;
                else{
                    boolean flag = false;
                    while (pq.size()!=0){
                        Shirt topShirt=pq.poll();
                        if(!used.get(topShirt)){
                            used.put(topShirt, true);
                            result[i]=topShirt.price;
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                        result[i]=-1;
                }
            }
            for(int x: result){
                System.out.print(x + " ");
            }
            System.out.println();

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
