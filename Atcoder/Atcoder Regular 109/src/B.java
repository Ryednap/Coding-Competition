import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

//* Concept is lot easier than normal but don't use mathematical function there are lot of precission error
//* User binary search.

public class B {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
        long n = fs.nextLong();

        long lo = 0, hi = n + 1;
        long ans = -1;
        while(lo <= hi){
            long mid = lo + (hi - lo)/2;
            if(F(mid, n)){
                lo = mid + 1;
                ans = mid;
            } else hi = mid - 1;
        }

        System.out.println(n - ans + 1);

    }

    static boolean F(long a, long b){
        double x = a;
        if(x * (x + 1)/2.0 > 1e18 + 100) return false;
        else return ( (a * (a + 1))/2 <= b + 1);
    }

    static class Pair{
        int first, second;
        Pair(int a, int b){
            this.first = a;
            this.second = b;
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