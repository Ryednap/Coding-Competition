import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;

public class D {
	static FastScanner fs = new FastScanner();

	public static void main(String[] args) throws IOException {
		int q = fs.nextInt();
		SortedSet<Pair> set = new TreeSet<Pair>();
		long sum = 0;
		for (int i = 0; i < q; ++i) {
			int type = fs.nextInt();
			if(type == 1) {
				int x = fs.nextInt();
				set.add(new Pair(x - sum, i));
			} else if(type == 2) {
				int x = fs.nextInt();
				sum += x;
			} else {
				Pair p = set.first();
				set.remove(p);
				System.out.println(p.first + sum);
			}
		}
	}

	static class Pair implements Comparable<Pair> {
		Long first;
		Integer second;
		public Pair(long a, int b) {
			this.first = a;
			this.second = b;
		}
		@Override
		public int compareTo(Pair p) {
			return this.first.compareTo(p.first);
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