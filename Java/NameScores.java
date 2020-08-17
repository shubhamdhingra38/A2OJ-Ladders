import java.io.*;
import java.lang.reflect.Array;
import java.nio.CharBuffer;
import java.util.*;

public class NameScores {
    static class StringCompare implements Comparator<String>{

        @Override
        public int compare(String o1, String o2) {
            return o1.compareTo(o2);
        }
    }
    public static void main(String[] args) throws IOException {
        Utility.FastReader fr = new Utility.FastReader();
        FileReader flrd = new FileReader("./files/p022_names.txt");
        ArrayList<String> arrList = new ArrayList<>();
        int c;
        boolean flag = false; //true is opened
        int i = -1;
        StringBuilder str = new StringBuilder();
        while((c = flrd.read()) != -1){
            if((char)c == '"'){
                if(!flag){
                    flag = true;
                    i++;
                    str.setLength(0);
                }
                else{
                    arrList.add(str.toString());
                    flag = false;
                }
            }
            else{
                str.append((char)c);
            }
        }
        Collections.sort(arrList);
        long result = 0;
        int stringScore = 0;
        String s;
        for(i=0; i<arrList.size(); ++i){
            s = arrList.get(i);
            stringScore = 0;
            System.out.println(s);
            for(int j=0; j<s.length(); ++j){
                stringScore += s.charAt(j)-'A'+1;
            }
            System.out.println(stringScore);
            result += (i+1) * (long)stringScore;
        }
        System.out.println(result);
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
