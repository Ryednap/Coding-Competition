import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class ShufflingParities {
    static FastScanner fs = new FastScanner();
    public static void main (String [] args) {
        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt();
            int [] a = fs.readArray(n);
            int oddReq = (n >> 1) + (n & 1);
            int evenReq = n - oddReq;
            int odd = 0;
            for (int i = 0; i < n; ++i) {
                if ((a[i] & 1) == 1) odd++;;
            }
            System.out.println(n - Math.abs(evenReq - odd));
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