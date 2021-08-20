import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// Easy Problem

// Greedy Algorithm : (Just Trace the example and you will get the idea).

/*
    When we put an item on the circle note that we have two sides one from the clockwise left and other from
    the ant-clockwise right. Means each one it can be used two times to maximise our result.
 */

public class D {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
        int N = fs.nextInt();
        int [] A = fs.readArray(N);

        sort(A);
        long answer = A[0];

        int curr = 1, turn = 0;
        for(int i = 2; i < N;++i){
            if(turn == 2){
                turn = 0;
                curr++;
            }
            answer += A[curr];
            ++turn;
        }
        System.out.print(answer);
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
        Collections.sort(list, Collections.reverseOrder());
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