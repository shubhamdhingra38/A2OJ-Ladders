import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LargestProductGrid {
    static long res = -1;
    static long max(long ...args){
        long res = -1;
        for(int i=0; i<args.length; ++i){
            res = Math.max(res, args[i]);
        }
        return res;
    }
    static long computeRight(int i, int j, int[][] arr){
        long res = 1;
        for(int x=j; x<Math.min(20, j+4); ++x){
            res *= arr[i][x];
        }
        return res;
    }
    static long computeLeft(int i, int j, int [][] arr){
        long res = 1;
        for(int x=j; x>=Math.max(0, j-3); --x){
            res *= arr[i][x];
        }
        return res;
    }
    static long computeLeftR(int i, int j, int [][] arr){
        long res = 1;
        for(int x=0; x<4; ++x){
            if(i-x < 0 || j-x < 0 || i+x >= 20 || j+x >= 20){
                break;
            }
            res *= arr[i-x][j+x];
        }
        return res;
    }
    static long leftDiag(int i, int j, int[][] arr){
        long res = 1;
        for(int x=0; x<4; ++x){
            if(i-x < 0 || j-x < 0){
                break;
            }
            res *= arr[i-x][j-x];
        }
        return res;
    }
    static long rightDiag(int i, int j, int[][] arr){
        long res = 1;
        for(int x=0; x<4; ++x){
            if(i+x >= 20 || j+x >= 20){
                break;
            }
            res *= arr[i+x][j+x];
        }
        return res;
    }
    static long computeDown(int i, int j, int[][] arr){
        long res = 1;
        for(int x=i; x<Math.min(20, i+4); ++x){
            res *= arr[x][j];
        }
        return res;
    }
    static long computeUp(int i, int j, int[][] arr){
        long res = 1;
        for(int x=i; x>=Math.max(0, i-3); --x){
            res *= arr[x][j];
        }
        return res;
    }
    static void dfs(int i, int j, int[][] arr){
        res = max(computeDown(i, j, arr), computeRight(i, j, arr), rightDiag(i, j, arr),
                computeLeftR(i, j, arr),res);
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int[][] arr = new int[20][20];
        for(int i=0; i<20; ++i){
            for(int j=0; j<20; ++j){
                arr[i][j] = fr.nextInt();
            }
        }
        for(int i=0; i<20; ++i){
            for(int j=0; j<20; ++j){
                dfs(i, j, arr);
            }
        }
        System.out.println(res);
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
