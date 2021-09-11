import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class PointMeeting {
    static FastScanner fs = new FastScanner();
    public static void main (String [] args) {
        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt();
            int [] X = fs.readArray(n);
            int [] Y = fs.readArray(n);
            
            int [][] dp = new int[n][n];
            for (int [] ar : dp) {
                Arrays.fill(ar, (int)1e9);
            }

            for (int i = 0; i < n; ++i) {
                dp[i][i] = 0;
                for (int j = i + 1; j < n; ++j) {
                    int x = Math.abs(X[i] - X[j]);
                    int y = Math.abs(Y[i] - Y[j]);
                    
                    int moves = 0;
                    if (x == 0 && y == 0) moves = 0;
                    else if (x == 0 || y == 0 || x == y) moves = 1;
                    else moves = 2;
                    dp[i][j] = dp[j][i] = moves;
                }
            }

            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
            int answer = (int)1e9;
            for (int [] ar : dp) {
                System.out.println(Arrays.toString(ar));
                answer = Math.min(answer, Arrays.stream(ar).sum());
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