import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;

public class C {
	static FastScanner fs = new FastScanner();

	public static void main(String[] args) throws IOException {
		int n = fs.nextInt();
		int m = fs.nextInt();
		int [] a = fs.readArray(n);
		int [] b = fs.readArray(m);
		b[m] = (int)1e9 + 10;
		a[n] = (int)1e9 + 10;

		Arrays.sort(a);
		Arrays.sort(b);
		int ans = (int)2e9 + 10;

		for (int i = 0, j = 0; i < n; ++i) {
			while (j < m && Math.abs(a[i] - b[j]) >= Math.abs(a[i] - b[j + 1])) {
				++j;
			}
			assert(j != m);
			ans = Math.min (ans, Math.abs(a[i] - b[j]));
		}
		System.out.println(ans);
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

		int nextInt() {
			return Integer.parseInt(next());
		}

		int [] readArray(int n) {
			int [] a = new int [n + 1];
			for (int i = 0; i < n; ++i) {
				a[i] = fs.nextInt();
			}
			return a;
		}
	}
}