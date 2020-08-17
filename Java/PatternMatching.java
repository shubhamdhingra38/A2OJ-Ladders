import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class PatternMatching {
    static int MAX = 55;
    static int MAX_SIZE = 105;
    static boolean match(int a, int b, String[] s){
        String s1, s2;
        s1 = s[a];
        s2 = s[b];
        int l = Math.min(s1.length(), s2.length());
        int cnt = 0;
        int ptr1, ptr2;
        ptr1 = ptr2 = 0;
        for(int i=0; i<l; ++i){
            if(s2.charAt(ptr1) != s1.charAt(ptr2)){
                if(s2.charAt(ptr1) == '*'){
                    ptr2 = s1.length()-ptr1-1;
                    ptr1++;
                }
                else if(s1.charAt(ptr2) == '*'){
                    ptr1 = s2.length()-ptr2-1;
                    ptr2++;
                }
                else{
                    return false;
                }
            }
            else{
                ptr1++;
                ptr2++;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int t= fr.nextInt();
        int n;
        String[] s = new String[MAX];
        int[][] states = new int[MAX_SIZE][26];
        String s1 = fr.nextLine();
        String s2 = fr.nextLine();
        s[0] = s1;
        s[1] = s2;
        System.out.println(match(0, 1, s));
//        while(t-- > 0){
//            n = fr.nextInt();
//            for(int i=0; i<n; ++i){
//                s[i] = fr.nextLine();
//            }
//            for(int i=0; i<MAX_SIZE; ++i){
//                for(int j=0; j<26; ++j){
//                    states[i][j] = 0;
//                }
//            }
//            boolean flag = true;
//            for(int i=0; i<n; ++i){
//                if(!flag){
//                    break;
//                }
//                for(int j=0; j<n; ++j){
//                    if(match(i, j, s) || match(j, i, s)){
//                        continue;
//                    }
//                    else{
//                        flag = false;
//                        break;
//                    }
//                }
//            }
//
//
//        }
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
