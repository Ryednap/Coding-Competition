import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;



public class B {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
        int N = fs.nextInt(), M = fs.nextInt();
        int [][] arr = new int[N][M];
        int mini = 1000;
        for(int i = 0; i < N; ++i){
            arr[i] = fs.readArray(M);
            for(int j = 0; j < M; ++j) mini = Math.min(mini, arr[i][j]);
        }

        int answer = (int)1e9;
        for(int i = 0; i <= mini; ++i){
            int total = 0;
            for(int row = 0; row < N; ++row){
                for(int col = 0; col < M; ++col){
                    total += Math.abs(i - arr[row][col]);
                }
            }
            answer = Math.min(answer, total);
        }
        System.out.println(answer);
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