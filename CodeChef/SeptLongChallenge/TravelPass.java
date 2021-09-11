import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class TravelPass {
    static FastScanner fs = new FastScanner();
    public static void main (String [] args) {
        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt(), a = fs.nextInt(), b = fs.nextInt();
            char [] s = fs.next().toCharArray();
            int answer = 0;
            for (Character ch : s) {
                if (ch == '0') answer += a;
                else answer += b;
            }
            System.out.println(answer);
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