import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Ok so I received one WA , and I know what's the reason for it (Some path's not considered).
 *
 *
 */

public class E {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args) {
        int n = fs.nextInt(), m = fs.nextInt();
        Graph g = new Graph(n);
        for(int i = 0; i < m; ++i) {
            int a = fs.nextInt(), b = fs.nextInt();
             g.AddEdge(a, b);
        }
        int ans = g.Solve();
        System.out.println(ans);
    }

    static class Graph {
        int nodes;
        static ArrayList<Integer> [] edges;
        static ArrayList<Integer> [] par;
        static int [] A;
        static boolean [] used;
        static ArrayList<Integer> order = new ArrayList<>();
        Graph(int n) {
            this.nodes = n;
            edges = new ArrayList[n + 1];
            par = new ArrayList[n + 1];
            for(int i = 0; i <= n; ++i) {
                edges[i] = new ArrayList<>();
                par[i] = new ArrayList<>();
            }
            used = new boolean[n + 1];
            A = fs.readArray(n);
        }
        public void AddEdge(int a, int b) {
            edges[a].add(b);
            par[b].add(a);
        }

        public void Dfs(int node) {
            used[node] = true;
           for(Integer child : edges[node]) {
               if(!used[child]) {
                   Dfs(child);
               }
           }
           order.add(node);
        }
        public int Solve() {
            for(int i = 1; i <= this.nodes; ++i) {
                if(!used[i]) {
                    Dfs(i);
                }
            }
           // System.out.println(order);
            int [] dp = new int[nodes + 1];
            int answer = -(int)2e9 + 10;
            for(Integer x : order) {
                if(dp[x] != 0) {
                    answer = Math.max(answer, dp[x] - A[x - 1]);
                }
                for(Integer p : par[x]) {
                    dp[p] = Math.max(dp[p], Math.max(A[x - 1], dp[x]));
                }
            }
            return answer;
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