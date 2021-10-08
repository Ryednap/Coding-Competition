import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;

public class Main {
	static FastScanner fs = new FastScanner();
	static final int OO = (int)1e9 + 10;

	public static void main(String[] args) throws IOException {
		int n = fs.nextInt();
		ArrayList<Pair> [] edges = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			edges[i] = new ArrayList<Pair> ();
		}
		for (int i = 0; i < n -1; ++i) {
			int a = fs.nextInt(),b = fs.nextInt(), c = 1;
			--a; --b;
			edges[a].add(new Pair(b, c));
			edges[b].add(new Pair(a, c));
		}

		long [] ans = new long [n];
		int [] size = new int [n];
		class Dfs1 {
			int dfs (int u, int p, long sum) {
				int num = 0;
				for (Pair c : edges[u]) {
					if (c.f != p) {
						num += dfs (c.f, u, sum + c.s);
					}
				}
				ans[0] += sum;
				size[u] = num;
				return size[u] + 1;
			}
		};

		class Dfs2 {
			void dfs (int u, int p, int w) {
				if (p != -1) {
					ans[u] = ans[p] + w * (n - 2 * size[u] - 2);
				}
				for (Pair c : edges[u]) {
					if (c.f != p) {
						dfs (c.f, u, c.s);
					}
				}
			}
		};

		Dfs1 dfs1 = new Dfs1();
		Dfs2 dfs2 = new Dfs2();

		dfs1.dfs(0, -1, 0);
		dfs2.dfs(0, -1, -1);

		for (long x : ans) {
			System.out.println (x);
		}
	}

	static class Pair {
		int f, s;
		Pair (int f, int s) {
			this.f = f;
			this.s = s;
		}
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