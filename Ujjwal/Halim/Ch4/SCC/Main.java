import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.*;

public class Main {
	static FastScanner fs = new FastScanner();
	static final int mod = (int)1e9 + 7;
	public static void main(String[] args) throws IOException{
		int qq = fs.nextInt();
		while (qq-- > 0) {
			int n = fs.nextInt();
			int [] a = fs.readArray(n);

			int ans = 0;
			for (int i = 0; i < 3; ++i) {
				int ones = 0;
				for (int j = 0; j < n; ++j) {
					if ((a[j] & (1 << i)) > 0)
						++ones;
				}
				ans = Add(ans, Mul(Sub(modPow(ones), 1), 1 << i));
			}
			System.out.println(ans);
		}

	}
	static int Add (int a, int b) {
		return ((a + b) % mod + mod)%mod;
	}

	static int Sub (int a, int b) {
		return ((a - b) % mod + mod) %mod;
	}

	static int Mul (int a, int b) {
		return (int)(((long)a * b)%mod + mod)%mod;
	}

	static int modPow (int b) {
		int res = 1;
		int a = 2;
		for (; b > 0; b >>= 1) {
			if ((b & 1) > 0)
				res = Mul(res, a);
			a = Mul(a, a);
		}
		return res;
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer token = new StringTokenizer("");

		String next() {
			while (!token.hasMoreTokens()) {
				try {
					token = new StringTokenizer(br.readLine());
				} catch (IOException ie){
					ie.printStackTrace();
				}
			}
			return token.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		int [] readArray (int n) {
			int [] a = new int [n];
			for (int i = 0; i < n; ++ i) {
				a[i] = nextInt();
			}
			return a;
		}
	}
}