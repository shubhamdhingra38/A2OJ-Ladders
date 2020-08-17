import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.BitSet;
import java.util.StringTokenizer;
import java.util.BitSet;

public class TenThousandthPrime {
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        BitSet b = new BitSet(100000000);
        int cnt = 0; int target = 10001;
        for(long i=2; i < 100000000; ++i){
            if(!b.get((int)i)){
                cnt++;
                if(target == cnt){
                    System.out.println(i);
                    break;
                }
                for(long j=i*i; j< 100000000; j+=i){
                    b.set((int)j);
                }
            }
        }
        System.out.println("DONE");
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
