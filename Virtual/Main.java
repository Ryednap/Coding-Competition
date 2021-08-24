import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

@FunctionalInterface
interface Solution {
    int solve (int i);
}

public class Main {
    static FastScanner fs = new FastScanner();
    public static void main(String[] args) {
        int n = fs.nextInt();
        int [] h = fs.readArray(n);
        int [] w = fs.readArray(n);
        int [] l = fs.readArray(n);

        int [] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        Solution ob;
        ob = (int i) -> {
            if (i == n)
                return 0;

            if (dp[i] == -1)
                return dp[i];

            
            for (int k = 0; k < i; ++k) {
                int [] a = {h[k], w[k], l[k]};
                int [] b = {h[i], w[i], l[i]};

            }
            
            return dp[i];
        };
       
    }

    static boolean compare (int [] a, int [] b) {
        
    }
    
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token = new StringTokenizer ("");

        String next() {
            while (!token.hasMoreTokens()) {
                try {
                    token = new StringTokenizer (br.readLine());
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
            int [] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = nextInt();
            }
            return a;
        }
    }
}