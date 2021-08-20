from pynput.keyboard import Key, Controller
from time import sleep
from argparse import ArgumentParser
import os, sys

def type(path=None, delay=None):
    if not delay:
        delay = 3
    
    # wait for few seconds before typing
    sleep(delay)
    
    # manually enter your code here or provide a path
    code = """
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Chocolates {
    static FastScanner fs = new FastScanner();
    static int n, m;
    static int [] a;
    static int [][] dp;
    public static void main(String[] args) {
        n = fs.nextInt();
        m = fs.nextInt();
        a = new int[n];
        dp = new int[n + 1][n + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        for(int i = 0; i < n; ++i) {
            a[i] = fs.nextInt();
        }

        int ans = brute(0, n - 1);
        System.out.println(ans == 1 ? "YES" : "NO");
    }   

    static boolean valid(int a, int b) {
        return (a < n && b >= 0 && a <= b);
    }

    static int brute(int i, int j) {
        if(a[i] != a[j])
            return 0;
        if(i == j)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 0;
        for (int his = 1; his <= m; ++his) {
            for (int her = 1; her <= m;  ++her) {
                if(valid(i + his, j - her))
                    dp[i][j] |= brute(i + his, j - her);
            }
        }
        return dp[i][j];
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
    }
}
    """
    if path:
        with open(path, 'r') as file:
            code = file.read()
        
    keyboard = Controller()
    for line in code.split('\n'):
        keyboard.type(line)
        keyboard.tap(Key.enter)
        keyboard.tap(Key.home)
    
if __name__ == '__main__':
    parser = ArgumentParser(description='Autotype the specified file')
    parser.add_argument('-p', '--path',
                        metavar='path',
                        type=str,
                        help='the path to the file')
    parser.add_argument('-t', '--time',
                        metavar='time',
                        type=int,
                        help='time delay before typing')
    
    args = parser.parse_args()
    path = args.path
    delay = args.time
    if path and not os.path.isfile(path):
        print('No such file exists. Input the correct path!')
        sys.exit(0)
    type(path, delay)
