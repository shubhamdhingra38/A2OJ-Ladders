import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class CountingSundays {
    public static void main(String[] args) {
        Utility.FastReader fr = new Utility.FastReader();
        int year_low = 1900, year_high = 2000;
        int result = 0;
        int days;
        int dayOfWeek = 7;
        for(int i=year_low; i<= year_high; ++i){
            for(int month=1; month <= 12; ++month){
                if(month == 2){
                    if(i%4 == 0){
                        if(i%100 == 0){
                            if(i%400 == 0){
                                days = 29;
                            }
                            else{
                                days = 28;
                            }
                        }
                        else{
                            days = 29;
                        }
                    }
                    else{
                        days = 28;
                    }
                }
                else if(month == 4 || month == 6 || month == 9 || month == 11){
                    days = 30;
                }
                else{
                    days = 31;
                }

                if(month == 9 && i == 1901){
                    System.out.println(dayOfWeek%7);
                }
                dayOfWeek %= 7;
                if(dayOfWeek == 6){
                    if(i>1900){
                        result++;
                    }
                }
                dayOfWeek += days;
            }
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
