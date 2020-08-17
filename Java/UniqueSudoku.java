import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class UniqueSudoku {

    //source code attribution: https://www.geeksforgeeks.org/sudoku-backtracking-7/
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

    static class Pair{
        int dx, dy;
        public Pair(int dx, int dy){
            this.dx=dx;
            this.dy=dy;
        }

        @Override
        public int hashCode() {
            return 31 * this.dx + dy;
        }
    }



    static class Solver {
        Utility.FastReader fr;

        public Solver(Utility.FastReader fr) {
            this.fr = fr;
        }

        static HashMap<Character, HashSet<Integer>> map;
        static char[][] colors;
        public static boolean isSafe(int[][] board,
                                     int row, int col,
                                     int num) {
            for (int d = 0; d < board.length; d++) {
                if (board[row][d] == num) {
                    return false;
                }
            }

            for (int r = 0; r < board.length; r++) {

                if (board[r][col] == num) {
                    return false;
                }
            }

            // if not in region
            char c=colors[row][col];
            HashSet<Integer> set=map.get(c);
            if(set.contains(num)) return false;
            return true;

        }

        public static boolean solveSudoku(
                int[][] board, int n) {
            int row = -1;
            int col = -1;
            boolean isEmpty = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 0) {
                        row = i;
                        col = j;

                        // we still have some remaining
                        // missing values in Sudoku
                        isEmpty = false;
                        break;
                    }
                }
                if (!isEmpty) {
                    break;
                }
            }

            if (isEmpty) {
                return true;
            }

            for (int num = 1; num <= n; num++) {
                if (isSafe(board, row, col, num)) {
                    board[row][col] = num;
                    HashSet<Integer> arr=map.get(colors[row][col]);
                    arr.add(num);
                    if (solveSudoku(board, n)) {
                        // print(board, n);
                        return true;
                    }
                    else {
                        // replace it
                        board[row][col] = 0;
                        arr.remove(num);
                    }
                }
            }
            return false;
        }

        void solve() {
            map=new HashMap<>();
            for(int i=0; i<26; ++i){
                char c=(char)('a'+i);
                map.put(c, new HashSet<>());
                c=(char)('A'+i);
                map.put(c, new HashSet<>());
            }
            colors=new char[7][7];
            int[][] board = new int[7][7];
            for(int i=0; i<7; ++i){
                for(int j=0; j<7; ++j){
                    board[i][j]=fr.nextInt();
                }
            }
            for(int i=0; i<7; ++i){
                String s=fr.nextLine();
                while (s.length()==0) {
                    s=fr.nextLine();
                }
//                System.out.println(s);
                int j=0;
                int cnt=0;

                while(cnt!=7){
                    if(Character.isAlphabetic(s.charAt(j))){
                        colors[i][cnt++]=s.charAt(j);
                    }
                    j++;
                }
            }

//            for(int i=0; i<7; ++i){
//                for(int j=0; j<7; ++j){
//                    System.out.print(colors[i][j]);
//                }
//                System.out.println();
//            }
            int N = board.length;

            if (solveSudoku(board, N)) {
                for(int i=0; i<7; ++i){
                    for(int j=0; j<7; ++j){
                        System.out.print(board[i][j] + " ");
                    }
                    System.out.println();
                }
            }
            else {
                System.out.println("NO");
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