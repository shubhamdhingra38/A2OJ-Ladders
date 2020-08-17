import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.Random;

public class CodedTriangleNumbers {
    public static void main(String[] args) throws Exception {
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

        void solve() throws Exception {
            FileReader fileReader = new FileReader("./files/p042_words.txt");
            int c;
            int res = 0;
            int score = 0;
            int mx = 0;
            boolean flag = false;
            ArrayList<Integer> arrList = new ArrayList<>();
            while((c = fileReader.read()) != -1){
                if((char)c == '"'){
                    if(flag){
                        flag = false;
                        arrList.add(score);
                        mx = Math.max(mx, score);
                    }
                    else{
                        score = 0;
                        flag = true;
                    }
                }
                else if((char)c != ','){
                    score += c - 'A' + 1;
                }
            }
            HashMap<Integer, Boolean> hmap = new HashMap<>();
            int i = 1;
            while(true){
                int num = ((i)*(i+1))/2;
                hmap.put(num, true);
                if(num > mx){
                    break;
                }
                i += 1;
            }
            for(int x: arrList){
                if(hmap.containsKey(x)){
                    res++;
                }
            }
            System.out.println(res);
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
