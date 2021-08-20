import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

class CountingPrimes {
	static FastScanner fs = new FastScanner();
	public static void main(String[] args) {
		int n = fs.nextInt();
		int [] rating = fs.readArray(n);
		int [] range = fs.readArray(n);
		int [] ans = new int[n];

		for(int i = 0; i < n; ++i) {
			int count = 0;
			for(int j = i - 1; j >= i - range[i]; --j) {
				assert(j >= 0);
				for(int k = 2; k <= rating[i]; ++k) {
					if(isPrime(k) && rating[i] % k ==0 && rating[j] % k == 0)
						count++;
				}
			}
			ans[i] = count;
		}

		for (int i = 0; i < n; ++i) {
			System.out.printf("%d ", ans[i]);
		}
		System.out.println();
	}

	static boolean isPrime(int n) {
		if(n == 3 || n == 2) return true;
		if(n % 2 == 0 || n % 3 == 0) return false;

		for(int i = 5; i <= Math.sqrt(n); ++i) {
			if(n % i == 0) return false;
		}
		return true;
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
		int [] readArray(int n) {
			int [] arr = new int[n];
			for (int i = 0; i < n; ++i) {
				arr[i] = nextInt();
			}
			return arr;
		}
	}
}