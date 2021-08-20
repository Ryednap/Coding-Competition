import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
	static FastScanner fs = new FastScanner();
	public static void main(String[] args) {
		int N = fs.nextInt();
		SegmentTree st = new SegmentTree(N);
		for(int i = 0; i < N; ++i) {
			int x = fs.nextInt();
			st.increment(i, i, x);
		}
		int qq = fs.nextInt();
		while (qq-- > 0) {
			int l = fs.nextInt();
			int r = fs.nextInt();
			if(N == 3) {
				System.out.println("Query " + l + " " + r  + " " + fs.tokCount());
			}
			if(fs.tokCount() > 0) {
				int val = fs.nextInt();
				if(l > r) {
					st.increment(l, N - 1, val);
					st.increment(0, r, val);
				} else st.increment(l, r, val);

			} else {
				long answer = 0;
				if(l > r) {
					answer = Math.min(st.minimum(l, N - 1), st.minimum(0, r));
				} else answer = st.minimum(l, r);
				System.out.println(answer);
			}
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

		Integer tokCount() {
			return token.countTokens();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; ++i)
				a[i] = nextInt();
			return a;
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; ++i) a[i] = nextLong();
				return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public double[] readDoubleArray(int n) {
			double[] a = new double[n];
			for (int i = 0; i < n; ++i) a[i] = nextDouble();
				return a;
		}
	}
};


interface QueryInterface {
	public void increment (int i, int j, long val);
	public long minimum(int i, int j);
}

class SegmentTree implements QueryInterface {
	private int n;
	private int [] lo, hi;
	private long [] min, delta;

	public SegmentTree (int n) {
		this.n = n;
		this.lo = new int[4 * n + 1];
		this.hi = new int[4 * n + 1];
		this.min = new long[4 * n + 1];
		this.delta = new long[4 * n + 1];
		init(1, 0, n - 1);
	}

	public void increment(int a, int b, long val) {
		increment(1, a, b, val);
	}

	public long minimum(int a, int b) {
		return minimum(1, a, b);
	}


	void init (int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;

		if(a == b) return;
		int mid = (a + b) >> 1;
		init(2 * i, a, mid);
		init(2 * i + 1, mid + 1, b);
	}

	void prop(int i) {
		delta[2 * i] += delta[i];
		delta[2 * i + 1] += delta[i];
		delta[i] = 0;
	}

	void update(int i) {
		min[i] = Math.min(min[2 * i] + delta[2 * i], min[2 * i+ 1] + delta[2 *i + 1]);
	}

	void increment(int i, int a, int b, long val) {
		if(lo[i] > b || hi[i] < a) // offset
			return;
		if(lo[i] >= a && hi[i] <= b) { // inset
			delta[i] += val;
			return;
		}

		// partial cover needs to explore this subtree
		prop(i); // first push the changes to the children
		increment(2 * i, a, b, val);
		increment(2 * i + 1, a, b, val);
		update(i); // now take the update from children
	}

	long minimum(int i, int a, int b) {
		if(lo[i] > b || hi[i] < b)
			return Long.MAX_VALUE;
		if(lo[i] >= a && hi[i] <= b)
			return min[i] + delta[i];

		prop(i);
		long minLeft = minimum(2 * i, a, b);
		long minRight = minimum(2 * i + 1, a, b);
		update(i);

		return Math.min(minLeft, minRight);
	}
};
