import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Minimax {
    static FastScanner fs = new FastScanner();
    static final int [] Scores = {3, 5, 2, 9, 12, 5, 23, 23};
    public static void main(String[] args) {
        final int n = Scores.length;
        final int h = (int) (Math.log10(n >> 1) / Math.log10(2)) + 1;

        int answer = minimax(0, 0, true, h);
        System.out.println("The optimal Value is " + answer);
    }

    static int minimax (int depth, int node, boolean isMax, int h) {
        if(depth == h) return Scores[node];

        int left = minimax(depth + 1, node << 1, !isMax, h);
        int right = minimax(depth + 1, (node << 1) + 1, !isMax , h);

        if(isMax) return Math.max(left, right);
        else return Math.min(left, right);

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
