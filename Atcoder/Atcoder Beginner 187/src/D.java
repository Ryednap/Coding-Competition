import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

// Unexpected Runtime Error

public class D {
    static FastScanner fs = new FastScanner();
    static final int Mod = (int)1e9 + 7;
    public static void main(String[] args) {
        int N = fs.nextInt();
        Pair [] arr = new Pair[N];
        long  A = 0, T = 0;
        for(int i = 0; i < N; ++i) {
            arr[i] = new Pair(fs.nextInt(), fs.nextInt());
            A += arr[i].f;
        }
        sort(arr);

        int answer = 0;
        for(int i = 0; i < N; ++i) {
            T += arr[i].f + arr[i].s;
            A -= arr[i].f;
            if(T > A) {
                answer = i + 1;
                break;
            }
        }
        System.out.print(answer);
    }


    static class Pair implements Comparable<Pair> {
        int f, s;
        Pair() {};
        Pair(int a, int b) {
            this.f =a;
            this.s = b;
        }

        @Override
        public int compareTo(Pair o) {
            long a = this.f * 2 + this.s;
            long b = o.f * 2 + o.s;
            return (int) (b - a);
        }
    }
    static void sort(Pair[] a) {
        ArrayList<Pair> list = new ArrayList<>(Arrays.asList(a));
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