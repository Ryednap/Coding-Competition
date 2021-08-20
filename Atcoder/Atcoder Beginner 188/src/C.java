import java.awt.image.BandedSampleModel;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Vector;


public class C {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args) {
        int n = fs.nextInt();
        n = 1 << n;
        int [] A = fs.readArray(n);
        int [] B = new int[n];
        for(int i = 0; i< n; ++i) {
            B[i] = i;
        }
        while(n > 2) {
            int [] C = new int[n >> 1];
            for(int i = 0, j = 0; i < n; i += 2){
                int a = A[B[i]];
                int b = i + 1 < n ? A[B[i + 1]] : 0;
                if(a > b ) C[j++] = B[i];
                else C[j++] = B[i + 1];
            }
            B = C;
            n >>= 1;
        }
        if(A[B[0]] < A[B[1]]) System.out.println(B[0] + 1);
        else System.out.println(B[1] + 1);
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