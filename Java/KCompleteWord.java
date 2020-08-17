import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KCompleteWord {
    static int MAX = (int)2e5 + 5;
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int t = fr.nextInt();
        int n, k;
        int[][] freq = new int[MAX][26];
        while (t-- > 0) {
            n = fr.nextInt(); k = fr.nextInt();
            String s = fr.nextLine();
            for(int i=0; i<k; ++i){
                for(int j=0; j<26; ++j){
                    freq[i][j] = 0; //reset
                }
                for(int j=i; j<n; j+=k){
                    freq[i][s.charAt(j)-'a'] += 1;
                }
                for(int j=i; j<n; j+=k){
                    freq[i][s.charAt(n-j-1)-'a'] += 1;
                }
            }
            int res = 0;
            for(int i=0; i<k; ++i){
                int max = 0;
                int total_cnt = 0;
                for(int j=0; j<26; ++j){
                    total_cnt += freq[i][j];
                    max = Math.max(max, freq[i][j]);
                }
                res += total_cnt - max;
            }
            System.out.println(res/2);
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
