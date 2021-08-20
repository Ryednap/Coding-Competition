import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {
    static FastScanner fs = new FastScanner();
    static final int nax = (int)1e5;
    static final long p = (int)1e4;
    public static void main(String[] args) {
        double x = fs.nextDouble(), y= fs.nextDouble(), r = fs.nextDouble();
        long X = (long) (x * p);
        long Y = (long) (y * p);
        long R = (long) (r * p);
        long answer = 0;
        for(int i = -nax; i <= nax; ++i) {
            long ii = i * p;
            long c = R * R - (ii - Y) * (ii - Y);
            if(c < 0) continue;
            c = (long) Math.sqrt(c);
            long l = -c + X, m = c + X;

            boolean w = (F(X, Y, R, l - 1, ii));
            boolean u = (F(X, Y, R, m + 1, ii));
            if(w || u) System.exit(0);
            l /= p;
            m /= p;

            System.out.println(w + " " + u);
            answer += (m - l + 1);
        }
        System.out.println(answer);
    }

    static boolean F(long X, long Y, long R, long x, long y) {
        return (x - X) * (x - X) + (y - Y) * (y - Y) <= R * R;
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
