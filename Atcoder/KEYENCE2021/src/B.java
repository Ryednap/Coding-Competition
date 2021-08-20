import javax.annotation.processing.SupportedSourceVersion;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class B {
    static FastScanner fs = new FastScanner();

    public static void main( String [] args) {
            int n = fs.nextInt(), k = fs.nextInt();
            long answer = 0;

            TreeMap<Integer,Integer> mapper = new TreeMap<>();
            for(int i = 0; i < n; ++i) {
                int x = fs.nextInt();
                int y = 1;
                if(mapper.containsKey(x)) y = mapper.get(x) + 1;
                mapper.put(x, y);
            }

            int required = 0, curr = k;
            for(Map.Entry<Integer, Integer> entry : mapper.entrySet()) {
                int x = entry.getKey();
                int y = entry.getValue();
                if(required != x) break;
                int next = Math.min(y, curr);
                answer += x * (long)(curr - next);
                curr = next;
                ++required;
            }
            answer += (required * (long) curr);
            System.out.println(answer);

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