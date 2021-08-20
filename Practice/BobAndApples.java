import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

class BobAndApples {
	static FastScanner fs = new FastScanner();
	static int n, m;
	static int [][][] dp;
	static int [] v, p;
	static final int OO = (int)1e9 + 10;

	public static void main(String[] args) {
		int qq = fs.nextInt();
		while (qq-- > 0) {
			n = fs.nextInt();
			m = fs.nextInt();
			dp = new int[n + 10][m + 10][3];
			for (int i = 0; i < n + 10; ++i)
				for (int j = 0; j < m + 10; ++j)
					for (int k = 0; k < 3; ++k)
						dp[i][j][k] = -1;

			v = new int[n];
			p = new int[n];
			for (int i = 0; i < n; ++i) {
				v[i] = fs.nextInt();
				p[i] = fs.nextInt();
			}
			int ans = brute(0, 0, 1);
			System.out.printf("%d\n", ans);
		}
	}


	static int brute(int i, int j, int k) {
		if(j > m) return -OO;
		if(i == n) {
			return 0;
		}

		if(dp[i][j][k] != -1)
			return dp[i][j][k];

		dp[i][j][k] = 0;
		int a = brute(i + 1, j, k); // don't choose
		int b = brute(i + 1, j + p[i], k) + v[i]; // choose without magic
		dp[i][j][k] = Math.max(a, b);
		if(k != 0) dp[i][j][k] = Math.max(dp[i][j][k], brute(i + 1, j + (p[i] / 2), 0) + v[i]); // choose with magic

		return Math.max(dp[i][j][k], 0);
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