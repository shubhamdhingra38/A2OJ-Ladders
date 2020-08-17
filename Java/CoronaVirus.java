import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class CoronaVirus {
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

        void solve() {
            int n, m;
            n=9;
            m=20;
            char[][] mat=new char[n+1][m+1];
            for(int i=0; i<n; ++i){
                String s=fr.next();
                char[] arr=s.toCharArray();
                for(int j=0; j<m; ++j){
                    mat[i][j]=arr[j];
                }
            }
//            for(int i=0; i<n; ++i){
//                for(int j=0; j<m; ++j){
//                    System.out.print(mat[i][j]);
//                }
//                System.out.println();
//            }
            Pair p1, p2, p3, p4;
            p1 = new Pair(1, -1);
            p2 = new Pair(-1, 1);
            p3 = new Pair(1, 1);
            p4 = new Pair(-1, -1);
            HashMap<Pair, Pair> clockwise = new HashMap<>();
            HashMap<Pair, Pair> anticlockwise = new HashMap<>();

            //case 1
            anticlockwise.put(p3, p2);
            clockwise.put(p3, p1);

            //case 2
            anticlockwise.put(p2, p4);
            clockwise.put(p2, p3);

            //case 3
            anticlockwise.put(p4, p1);
            clockwise.put(p4, p2);

            //case 4
            anticlockwise.put(p1, p3);
            clockwise.put(p1, p4);

            ArrayList<Pair> trajectory=new ArrayList<>();
            trajectory.add(new Pair(0, 0));
            int numBoundaryHits=0;
            int dX, dY;
            dX = 1;
            dY = 1;
            int currX, currY;
            currX = currY = 0;
            Pair currentGo = p3;
            String currentGoing="";
            while(numBoundaryHits != 2){
                dX=currentGo.dx;
                dY=currentGo.dy;
                currX += dX;
                currY += dY;
                trajectory.add(new Pair(currX, currY));
//                System.out.println(currX + " and " + currY);
                if(mat[n-currY-1][currX]=='a'){
                    //anticlockwise
//                    System.out.println("HERE");
                    Pair newCurrentGo=anticlockwise.get(currentGo);
//                    System.out.println("new pair is " + newCurrentGo.dx + " and " + newCurrentGo.dy);
                    currentGo=newCurrentGo;
                    //infect
                    mat[n-currY-1][currX]='-';
                    currentGoing="anticlockwise";
                }
                else if(mat[n-currY-1][currX]=='c'){
//                    System.out.println("clockwise here");
                    //clockwise
                    Pair newCurrentGo=clockwise.get(currentGo);
                    currentGo=newCurrentGo;
                    //infect
                    mat[n-currY-1][currX]='-';
                    currentGoing="clockwise";
                }
                else if(mat[n-currY-1][currX]=='*'){
                    //boundary
//                    System.out.println("HIT BOUNDARY");
                    numBoundaryHits++;
                    if(numBoundaryHits==2) break;
                    if(n-currY-1==0 || n-currY-1 == n-1){
                        if(n-currY-1==0){
                            if(currentGo.dx==1) {
                                currentGo=p1;
                            }
                            else{
                                currentGo=p4;
                            }
                        }
                        else{
                            if(currentGo.dx==1){
                                currentGo=p3;
                            }
                            else{
                                currentGo=p2;
                            }
                        }

                    }
                    else if(currX==0 || currX==m-1){
                        if(currX==0){
                            if(currentGo.dy==1){
                                currentGo=p3;
                            }
                            else{
                                currentGo=p1;
                            }
                        }
                        else{
                            if(currentGo.dy==1){
                                currentGo=p2;
                            }
                            else{
                                currentGo=p4;
                            }
                        }
                    }
                }
                else if(mat[n-currY-1][currX]=='-'){
                    break;
                }
            }

            //OUTPUT
            for(Pair p: trajectory){
                System.out.println(p.dx + " " + p.dy);
            }

            int infected, safe;
            infected = safe = 0;
            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                    System.out.print(mat[i][j]);
                    if(mat[i][j]=='-') infected++;
                    else if(mat[i][j]=='a'||mat[i][j]=='c') safe++;
                }
                System.out.println();
            }

            System.out.println("safe="+safe);
            System.out.println("infected="+infected);


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

