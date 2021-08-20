import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class B {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
        int n = fs.nextInt();
        int [] x = new int[n];
        int [] y = new int[n];
        for(int i = 0; i < n; ++i) {
            x[i] = fs.nextInt();
            y[i] = fs.nextInt();
        }
        int answer = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j){
                if(Valid(x[i], y[i], x[j], y[j])){
                    ++answer;
                }
            }
        }
        System.out.println(answer);
    }

    static boolean Valid(int x1, int y1, int x2, int y2) {
        int num = y2 - y1;
        int deno = x2 - x1;
        if(deno == 0) return false;
        double res = (double)num / deno;
        return res >= -1 && res <= 1;
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