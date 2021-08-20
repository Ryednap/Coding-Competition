import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class D {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args) {
        int n = fs.nextInt();
        String [] S = new String[n];
        for(int i = 0; i < n; ++i) {
            S[i] = fs.next();
        }
        System.out.println(Arrays.toString(S));
        long [][][] ans = new long[4][2][2];
        int [][]A = {{0, n/4}, {n/4, n/2}, {n/2 , (3*n)/4}, {(3 * n)/4, n} };

        for(int i = 0; i < 4; ++i) {
            long [] temp = Calculate(n, A[i][0], A[i][1], S, true);
            ans[i][1][0] = temp[0];
            ans[i][1][1] = temp[1];
            System.out.println(Arrays.toString(temp));

            temp = Calculate(n, A[i][0], A[i][1], S, false);
            ans[i][0][0] = temp[0];
            ans[i][0][1] = temp[1];
            System.out.println("hello " + Arrays.toString(temp));
        }
        long answer = Brute(ans, 0, 0, 1) + Brute(ans, 1, 0, 1);

        System.out.println(answer);
    }

    static long Brute(long [][][] a, int sig, int i, long tot) {
        if(i == 4) return tot;
        return Brute(a, 0, i + 1, tot * a[i][sig][0]) +
                Brute(a, 1, i + 1, a[i][sig][1]);
    }
    static boolean Solve(String s, long x, boolean y ) {
        boolean a = x > 0;
        if(s.equals("AND")) return a & y;
        else return a | y;
    }

    static long[] Calculate(int n, int lo, int hi, String [] S, boolean prev) {
        long [] ans = new long[2];
        for(long i = 0; i < 1L << n; ++i) {
            boolean val = false;
            int done = -1;
            for(int j = lo; j < hi; ++j) {
                long bit = (i & (1L << j));
                if(done == -1) {
                    done = 1;
                    val = Solve(S[j], bit, prev);
                } else val = Solve(S[j], bit, val);
            }
            if(done == -1) continue;
            if(!val) ans[0]++;
            else ans[1]++;
        }
        return ans;
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