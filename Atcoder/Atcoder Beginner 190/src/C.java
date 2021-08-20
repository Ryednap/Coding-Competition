import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class C {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args) {
        int n = fs.nextInt(), m = fs.nextInt();
        int [] A = new int[m];
        int [] B = new int[m];
        for(int i = 0; i < m; ++i) {
            A[i] = fs.nextInt();
            B[i] = fs.nextInt();
        }
        int k = fs.nextInt();
        int [] C = new int[k];
        int [] D = new int[k];
        for(int i = 0; i < k; ++i) {
            C[i] = fs.nextInt();
            D[i] = fs.nextInt();
        }

        int ans = 0;
        for(int i = 0; i < (1 << k); ++i) {
            int [] dish = new int[n + 1];
            for(int j = 0; j < k; ++j) {
                int bit = i & (1 << j);
                if(bit > 0) {
                    dish[D[j]]++;
                } else {
                    dish[C[j]]++;
                }
            }

            int cnt = 0;
            for(int j = 0; j < m; ++j) {
                if(dish[A[j]] > 0 && dish[B[j]] > 0) ++cnt;
            }
            ans = Math.max (ans, cnt);
        }
        System.out.println(ans);
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