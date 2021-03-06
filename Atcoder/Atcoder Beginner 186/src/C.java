import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class C {
    static FastScanner fs = new FastScanner();

    public static void main(String[] args) {
            int N = fs.nextInt();
            int answer = 0;
            for(int i = 1; i <= N; ++i){
                if(Decimal(i) && Octal(i)) ++answer;
            }
            System.out.println(answer);
    }
    static boolean Decimal(int x){
        while(x > 0){
            int digit = x%10;
            if(digit == 7) return false;
            x /= 10;
        }
        return true;
    }
    static boolean Octal(int x){
        String str = Integer.toOctalString(x);
        for(int i = 0; i < str.length(); ++i){
            if(str.charAt(i) == '7') return false;
        }
        return true;
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