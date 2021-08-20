import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.function.Function;

/** Concepts :-
 *  How to discrete the event's
 *  How to solve the problem's in which data for intersecting event is large.
 */
public class D {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args) {
        int n = fs.nextInt() , C = fs.nextInt();
        ArrayList<Pair> event = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            int a = fs.nextInt(), b = fs.nextInt(), c = fs.nextInt();
            event.add(new Pair(a, c));
            event.add((new Pair(b + 1, -c)));
        }
        Collections.sort(event);

        long answer = 0;
        long cost = 0, time = 0;
        for(Pair p : event) {
            long dt = p.f - time;
            answer += Math.min(C, cost) * dt;
            time = p.f;
            cost += p.s;
        }
        assert (cost == 0);
        System.out.print(answer + "\n");
    }

    static class Pair implements Comparable<Pair> {
        long f, s;
        Pair(long a, long b) {
            this.f = a;
            this.s = b;
        }
        public int compareTo(Pair p) {
            return (int) (f - p.f);
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