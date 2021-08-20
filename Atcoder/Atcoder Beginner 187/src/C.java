import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.security.KeyPair;
import java.util.*;


public class C {
    static FastScanner fs = new FastScanner();
    public static void main(String[] args) {
            int n = fs.nextInt();
            Map<String, Boolean> m = new HashMap<>();
            String ans = "";
            for(int i = 0; i < n; ++i) {
                String s = fs.next();
                m.putIfAbsent(s, true);
            }

            for(Map.Entry<String, Boolean> p : m.entrySet()) {
                String s = p.getKey();
                if(s.charAt(0) != 0) {
                    String t = "!" + s;
                    if(m.containsKey(t)) ans = s;
                }
            }
            System.out.println(ans.length() == 0 ? "satisfiable" : ans);
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