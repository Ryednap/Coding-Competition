import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

class Posters {
	static FastScanner fs = new FastScanner();
	public static void main(String[] args) {
		int test_case = fs.nextInt();
		while (test_case > 0) {
			test_case--;
			solve();
		}
	}

	static void solve() {
		int n = fs.nextInt();
		SegmentTree st = new SegmentTree();
		//st.debug();

		for( int i = 0; i < n; ++i ) {
			int l = fs.nextInt() - 1;
			int r = fs.nextInt() - 1;
			st.update(l, r, i);
		}

		Set<Integer> answer = new HashSet<Integer> ();
		for(int i = 0; i < st.n; ++i) {
			int value = st.query(i);
			if(value != -1)
				answer.add(value);
		}
		//st.debug();

		System.out.println(answer.size());
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


class SegmentTree {
	private int [] st;
	private int [] lo, hi;
	public final int n = (int)1e7;

	public SegmentTree() {
		st = new int[4 * n + 1];
		lo = new int[4 * n + 1];
		hi = new int[4 * n + 1];
		for(int i = 0; i < st.length; ++i) {
			st[i] = -1;
		}
		init(1, 0, n - 1);
	}

	public int query(int a) {
		return query(1, a);
	}

	public void update(int a, int b, int c) {
		 update(1, a, b, c);
	}

	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;
		if(a == b) {
			st[i] = -1;
			return;
		}
		int m = (a + b) >> 1;
		init(i << 1, a, m);
		init((i << 1) + 1, m + 1, b);
	}

	void prop(int i) {
		if(st[i] == -1)
			return;
		st[i << 1] = st[i];
		st[(i << 1) + 1] = st[i];
		st[i] = -1;
	}

	int query(int i, int a) {
		if(lo[i] > a || hi[i] < a) return -1;
		if(lo[i] == a && hi[i] == a) {
			return st[i];
		}

		prop(i);
		int left = query(i << 1, a);
		int right = query((i << 1) + 1, a);
		if(left != -1)
			return left;
		else 
			return right;
	}

	void update(int i, int a, int b, int val) {
		if(lo[i] > b || hi[i] < a)
			return;
		if(lo[i] >= a && hi[i] <= b) {
			st[i] = val;
			return;
		}
		prop(i);
		update(i << 1, a, b, val);
		update((i << 1) + 1, a, b, val);
	}
	public void debug() {
		System.out.println(Arrays.toString(st));
	}
}