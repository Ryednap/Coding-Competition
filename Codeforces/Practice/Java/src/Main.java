import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;


public class Main {
   static FastScanner fs = new FastScanner();
   static PrintWriter out = new PrintWriter(System.out);
   public static void main( String [] args) {
        String st = fs.next();


        while(!st.equals("END")) {
            StringTokenizer p = new StringTokenizer(st);
            StringBuilder a = new StringBuilder();
            StringBuilder b = new StringBuilder();

            boolean split = false;
            while(!p.hasMoreTokens()) {
                String s = p.nextToken();
                if(s.equals("by")) split = true;
                else if(split) b.append(s);
                else a.append(s);
            }

            st = fs.next();
        }

   }

   static class Book {
        String t, a;
        TreeMap<String, String> map = new TreeMap<>();
        Book () {}
        Book (String a, String b) {
            this.t = a;
            this.a = b;
            map.put(a, b);
        }
        String getAuthor(String title) {
            return map.get(title);
        }

   }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer("");

        String next() {
            while (!token.hasMoreTokens()) {
                try {
                    token = new StringTokenizer(br.readLine());
                } catch (IOException ie) {
                    ie.printStackTrace();
                }
            }
            return token.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = nextInt();
            return a;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; ++i) a[i] = nextLong();
            return a;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public double[] readDoubleArray(int n) {
            double[] a = new double[n];
            for (int i = 0; i < n; ++i) a[i] = nextDouble();
            return a;
        }
    }
}