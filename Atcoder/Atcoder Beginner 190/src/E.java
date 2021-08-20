import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class E {
    static FastScanner fs = new FastScanner();
    static final int OO = (int)1e6 + 10;

    public static void main( String [] args) {
        int n = fs.nextInt(), m = fs.nextInt();
        ArrayList<Integer> [] edges = new ArrayList[n + 1];
        for(int i = 0; i <= n; ++i) {
            edges[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; ++i) {
            int a = fs.nextInt(), b = fs.nextInt();
            edges[a].add(b);
            edges[b].add(a);
        }

        int k; k = fs.nextInt();
        int [] C = fs.readArray(k);

        int [][] dist = new int[k][k];
        class BFS {
            BFS() {}
            int Solve (int a, int b) {
                int [] number = new int[n + 1];
                boolean [] used = new boolean[n + 1];
                for(int i = 0; i <= n; ++i) number[i] = OO;
                number[a] = 0;
                Queue<Integer> q = new LinkedList<>();
                q.add(a);
                while (!q.isEmpty()) {
                    int node = q.poll();
                    used[node] = true;
                    if(node == b) break;
                    for(Integer child : edges[node]) {
                        if(!used[child]) {
                            number[child] = number[node] + 1;
                            q.add(child);
                        }
                    }
                }
                return number[b];
            }
        }
        for(int i = 0 ; i < k; ++i) {
            for(int j = 0; j < k; ++j) {
                BFS ob = new BFS();
                dist[i][j] = ob.Solve(C[i], C[j]);
            }
        }

        long [][] dp = new long[k + 1][(1 << k) + 5];
        for(int i = 0; i <= k; ++i) {
            Arrays.fill(dp[i], -1);
        }

        class DP {
            DP () {}
            long Brute(int i, int j) {
                if(j == (1 << k) - 1) return 0;
                if(dp[i][j] != -1) return dp[i][j];
                long ans = OO;

                for(int bit = 0; bit < k; ++bit) {
                    int val = j & (1 << bit);
                    if(val == 0) {
                        ans = Math.min(ans, Brute(bit, j | (1 << bit)) + dist[i][bit]);
                    }
                }

                return dp[i][j] = ans;
            }
        }

        DP solver = new DP();
        long answer = OO;
        for(int i = 0; i < k; ++i) {
            answer = Math.min(answer, solver.Brute(i, 1 << i));
        }
        if(answer >= OO) answer = -1;
        else answer++;
        System.out.println(answer);
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