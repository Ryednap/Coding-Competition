import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class D {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args) {
         long N = fs.nextLong();
         long n = 2 * N;

         class Insert {
             final Set<Pair> seq = new HashSet<>();
             Insert() {}

             void insert (long x, long y ) {
                 long a = x + y - 1;
                 long b = y - x + 1;
                 if(a % 2 != 0 || b % 2 != 0) return;
                 a >>= 1;
                 b >>= 1;
                 if(a > b) {
                     long temp = b;
                     b = a;
                     a = temp;
                 }
                 long sum = ((b - a + 1) * (a + b)) >> 1;
                 if(sum != N) return;
                 seq.add(new Pair(a, b));
             }
         }

         Insert solver = new Insert();
         for(int i = 1; i <= Math.sqrt(n); ++i) {
             if(n % i == 0) {
                 solver.insert(i, n / i);
                 solver.insert(n / i , i);
             }
         }
         System.out.println(solver.seq.size());

    }

    static class Pair {
        long f, s;
        Pair(long a, long b) {
            f = a;
            s = b;
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