import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class C {
    static FastScanner fs = new FastScanner();
    static final int Mod  = 99824435;
    static final int nax = 5100;

    static int [][][] dp = new int[nax][nax][4];
    static char [][] grid;
    static int n, m, k;

    public static void main( String [] args) {
        n = fs.nextInt();
        m = fs.nextInt();
        k = fs.nextInt();

        grid = new char[n][m];
        for(int i = 0; i < n; ++i) {
            for(int j= 0; j < m; ++j) {
                grid[i][j] = '.';
                for(int pp = 0; pp < 4; ++pp) {
                    dp[i][j][pp] = -1;
                }
            }
        }

        for (int i = 0; i < k; ++i) {
            int a = fs.nextInt(), b = fs.nextInt();
            char ch = fs.next().charAt(0);
            grid[a-1][b-1] = ch;
        }

        int answer = Solve(0,0,0);
        System.out.println(answer);

    }

    static int Solve(int i, int j, int k) {
        if(i == n - 1 && j == m - 1) {
            return 1;
        }

        if(i >= n || j >= m) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(grid[i][j] == 'R') {
            return dp[i][j][k] = Solve(i, j + 1, f('R'));

        } else if(grid[i][j] == 'D') {
            return dp[i][j][k] = Solve(i + 1, j , f('D'));

        } else if(grid[i][j] == 'X') {
            return dp[i][j][k] = Solve(i+ 1, j , f('X')) + Solve(i, j + 1, f('X'));

        } else {
            int  a = 0;
            a = Add(a, Solve(i ,j + 1, f('R')));
            a = Add(a, Solve(i + 1, j , f('D')));
            a = Add(a, Solve(i + 1, j, f('X')));
            a = Add(a, Solve(i, j + 1, f('X')));
            return dp[i][j][k] = a;
        }
    }

    static int f(char ch ) {
        if(ch == 'R') return  1;
        if(ch == 'D') return 2;
        if(ch == 'X') return 3;
        assert (false);
        return -1;
    }

    static int Add(int a, int b) {
        return ( ( a + b)%Mod + Mod)%Mod;
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