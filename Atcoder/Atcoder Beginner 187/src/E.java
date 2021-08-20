import jdk.jshell.EvalException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class E {
    static FastScanner fs = new FastScanner();
    static final int nax = (int)2e5 + 10;
    static ArrayList<Integer> [] edges = new ArrayList[nax];
    static int [] parent = new int[nax];
    static long [] val = new long[nax];

    public static void main(String [] args) {
        int N = fs.nextInt();
        for(int i = 0; i < nax; ++i){
            edges[i] = new ArrayList<>();
        }

        Pair [] arr = new Pair[N + 1];
        for(int i = 1; i < N; ++i) {
            int a = fs.nextInt(), b = fs.nextInt();
            arr[i] = new Pair(a, b);
            edges[a].add(b);
            edges[b].add(a);

        }

        Dfs0(1, 0);
        int qq = fs.nextInt();
        for(int i = 0; i < qq; ++i) {
            int t = fs.nextInt(),e = fs.nextInt(), x = fs.nextInt();
            int a = arr[e].f , b = arr[e].s;
            if(t == 2) {
                int temp = a;
                a = b;
                b = temp;
            }

            if(parent[a] == b) {
                val[a] += x;
            } else {
                val[1] += x;
                val[b] -= x;
            }
        }

        Dfs0(1,0);
        for(int i = 1; i <= N; ++i) {
            System.out.println(val[i]);
        }

    }

    static void Dfs0(int node, int par) {
        parent[node] = par;
        val[node] += val[par];
        for(int child : edges[node]) {
            if(child != par) {
                Dfs0(child, node);
            }
        }
    }

    static class Pair {
        int f, s;
        Pair(int f, int s) {
            this.f = f;
            this.s = s;
        }
    }

    static void sort(int[] a) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i : a) list.add(i);
        Collections.sort(list);
        for (int i = 0; i < a.length; ++i) a[i] = list.get(i);
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