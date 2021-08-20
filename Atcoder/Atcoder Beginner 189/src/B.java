import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class B {
    static FastScanner fs = new FastScanner();
    static final int EPS = (int)1e-12;
    public static void main( String [] args) {
            int n = fs.nextInt(), x = fs.nextInt();
            boolean done = false;
            double total = 0;
            for(int i = 0; i < n; ++i) {
                int a = fs.nextInt(), p = fs.nextInt();
                double curr = a * (double)p / 100;
                total += curr;
                if(x - total < EPS) {
                    System.out.println(i + 1);
                    done = true;
                    break;
                }
            }
            if(!done) System.out.println(-1);
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