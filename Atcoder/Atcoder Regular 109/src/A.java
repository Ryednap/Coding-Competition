import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// Constructive , Math.

// Consider the sequence A1, B1, A2,... A100, B100. Here two move from A1 to A2. we can do that with 1 y move and
// 2 x move. So let t = min(2 * x, y) , also the last move is always x so note that the difference b/w any A and B
// in the sequence is |2 * a - 2 * b + 1|.


public class A {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
        int a = fs.nextInt(), b = fs.nextInt(), x = fs.nextInt(), y = fs.nextInt();
        int answer = 0;
        int p1 = Math.abs(a - b);
        if(p1 == 0){
            answer = x;

        } else if(p1 == 1){
            if(a > b) answer = Math.min(x, x + y);
            else answer = Math.min(3 * x , x + y);

        } else {
            int min = Math.min(2 * x, y);
            int d = Math.abs(2 * b - 2 * a + 1);
            answer = d/2 * min + x;
        }

       System.out.println(answer);
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