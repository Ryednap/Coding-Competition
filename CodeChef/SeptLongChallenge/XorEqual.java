import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class XorEqual {
    static FastScanner fs = new FastScanner();
    public static void main (String [] args) {
        int t = fs.nextInt();
        while (t-- > 0) {
           int n = fs.nextInt(), x = fs.nextInt();
           int [] a = fs.readArray(n);
           int [] b = new int[n + 1];
       
           Map<Integer, Integer> countA = new HashMap<Integer, Integer> ();
           Map<Integer, Integer> countB = new HashMap<Integer, Integer> ();
           for (int i = 0; i < n; ++i) {
                b[i] = a[i] ^ x;
                Integer value = countA.get(a[i]);
                if (value == null) value = 0;
                countA.put(a[i], value + 1);

                if (b[i] != a[i]) {
                    value = countB.get(b[i]);
                    if (value == null) value = 0;
                    countB.put(b[i], value + 1);
                }
           }

           int answer = 0, operations = Integer.MAX_VALUE;
           for (int i = 0; i < n; ++i) {
               Integer p = countA.get(a[i]), q = countB.get(a[i]);
                if (p == null) p = 0;
                if (q == null) q = 0;
                int value = p + q;
               if (value > answer) {
                   answer = value;
                   operations = q;
               } else if (value == answer) operations = Math.min(operations, q);
           }
           System.out.println (answer + " " + operations);
        }
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer("");

        String next () {
            while (!token.hasMoreTokens()) {
                try {
                    token = new StringTokenizer(br.readLine());
                } catch (IOException ie) {
                    ie.printStackTrace();
                }
            }
            return token.nextToken();
        }

        int nextInt () {
            return Integer.parseInt(next());
        }

        int [] readArray (int n) {
            int [] a = new int [n];
            for (int i = 0; i < n; ++i) {
                a[i] = nextInt();
            }
            return a;
        }
    }
}