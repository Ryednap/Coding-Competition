import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class AirlineRestrictions {
    static FastScanner fs = new FastScanner();
    public static void main (String [] args) {
        int t = fs.nextInt();
        while (t-- > 0) {
            int a = fs.nextInt(), b = fs.nextInt(), c = fs.nextInt();
            int d = fs.nextInt(), e = fs.nextInt();
            int [] ar = {a, b, c};
            Arrays.sort(ar);
            boolean ok = false;
            for (int i = 0 ;i < 3; ++i) {
                for (int j = i + 1; j < 3; ++j) {
                    int sum = ar[i] + ar[j];
                    int carry = ar[0] + ar[1] + ar[2] - sum;
                    if (sum <= d && carry <= e) ok |= true;
                }
            }
            System.out.println(ok ? "YES" : "NO");
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