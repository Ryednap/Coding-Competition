import java.io.IOException;
import java.util.*;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
    static FastScanner fs = new FastScanner();
    public static boolean checkMove(char[][] board, int rMove, int cMove, char color) {
        board[rMove][cMove] = color;
        final int n = 8;
        final int [] dx = {0, 0, 1, 1, -1, -1, 1, -1};
        final int [] dy = {1, -1, 1, -1, -1, 1, 0, 0};

        boolean ok = false;
        for (int ii = 0; ii < 8; ++ii) {
           class Solver {
              public  boolean dfs (int x, int y, int cnt, int i) {
                 if (board[x][y] == board[rMove][cMove]) {
                    return cnt >= 3;
                 }

                 if (valid (x + dx[i], y + dy[i]))
                    return dfs (x + dx[i], y + dy[i], cnt + 1, i);
                return false;
              }
              public boolean valid (int x, int y) {
                 if(x < 0 || y < 0 || x >= n || y >= n)
                    return false;
                 return true;
                }
            }
            Solver ob = new Solver();
            if (ob.valid(rMove + dx[ii], cMove + dy[ii])) {
                ok |= ob.dfs (rMove + dx[ii], cMove + dy[ii], 2, ii);
            }
        }   
        return ok;
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

    Integer nextInt() {
        return Integer.parseInt(next());
    }
    Long nextLong() {
        return Long.parseLong(next());
    }
    int [] readArray(int n) {
        int [] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nextInt();
        }
        return arr;
    }
}
}