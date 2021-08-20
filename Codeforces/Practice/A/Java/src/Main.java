import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static FastScanner fs = new FastScanner();
    static final int nax = 70;
    static int n, m;
    static BigInteger [] dp = new BigInteger[nax];

    public static void main(String [] args) {
        n = fs.nextInt();
        m = fs.nextInt();

        int cases = 0;
        while (n < 61) {
            for(int i = 0; i < nax; ++i) {
                dp[i] = new BigInteger("-1");
            }
            BigInteger answer = Brute(n);
            System.out.println("Case " + ++cases + ": " + answer.toString());
            n = fs.nextInt();
            m = fs.nextInt();
        }
    }

    static BigInteger Brute(int i) {
        if(i <= 1) return BigInteger.ONE;
        if(!dp[i].equals(new BigInteger("-1")))  return dp[i].add(BigInteger.ONE);

        dp[i] = BigInteger.ZERO;
        for(int j = 1; j <= m; ++j) {
            dp[i] = dp[i].add(Brute(i - j));
        }
        return dp[i].add(BigInteger.ONE);
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
