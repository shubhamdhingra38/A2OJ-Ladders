import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Round85A {
    static int MAX = 105;
    static class Pair{
        int x, y;
        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int t = fr.nextInt();
        int n;
        Pair[] scores = new Pair[MAX];
        int x, y;
        while(t-- > 0){
            n = fr.nextInt();
            for(int i=0; i<n; ++i){
                x = fr.nextInt();
                y = fr.nextInt();
                scores[i] = new Pair(x, y);
            }
            boolean flag = true;
            if(scores[0].x < scores[0].y){
                flag = false;
            }
            for(int i=1; i<n; ++i){
                if(scores[i].x < scores[i-1].x){ //if plays decrease
                    flag = false;
                }
                else if(scores[i].y < scores[i-1].y){ //if clears decrease
                    flag = false;
                }
                else if(scores[i].y != scores[i-1].y && ((scores[i].x - scores[i-1].x) < (scores[i].y - scores[i-1].y))){
                    flag = false;
                }
            }
            if(flag){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
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
