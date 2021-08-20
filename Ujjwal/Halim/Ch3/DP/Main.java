import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static FastScanner fs = new FastScanner();
	static final int OO = (int)1e9 + 10;
	public static void main(String[] args) throws IOException {
		int n = fs.nextInt();
		int [] change = new int[n + 1];
		int [] store = new int[n + 1];
		int [][] mat = new int[n + 1][n + 1];

		Arrays.fill(store, -1);
		for (int vertex = 1; vertex <= n; ++vertex) {
			int got = query (vertex);
			
			System.out.println("vertex " + vertex + " query " + got);

			int count = 0;
			for (int i = 1; i < vertex; ++i) {
				int prev = query (i) ^ (change[i] % 2);

				if(prev != store[i]) {
					count++;
					mat[vertex][i] = mat[i][vertex] = 1;
				}
				for (int j = 1; j < i; ++j) {
					if (mat[i][j] == 1)
						change[j]++;
				}

			}	
			store[vertex] = got ^ ((count + change[vertex]) % 2);
			for (int i = 1; i <= n; ++i) {
				if (mat[vertex][i] == 1)
					change[i]++;
			}
		}

		System.out.println("!");
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				System.out.printf("%d", mat[i][j]);
			}
			System.out.println();
		}
		System.out.flush();
	}	

	static int query (int vertex) {
		System.out.println("? " + vertex);
		System.out.flush();
		String s = fs.next();
		return s.equals("B") ? 1 : 0;
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer token = new StringTokenizer("");

		String next() {
			while (!token.hasMoreTokens()) {
				try {
					token = new StringTokenizer(br.readLine());
				} catch (IOException ie) {
					return "-999999999999";
				} catch (NullPointerException np) {
					return "-999999999999";
				}
			}
			return token.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		int [] readArray (int n) {
			int [] a = new int[n + 1];
			for (int i = 0; i < n; ++i) {
				a[i] = fs.nextInt();
			}
			return a;
		}
	}
}