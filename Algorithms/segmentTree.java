interface QueryInterface {
	public void increment (int i, int j, int val);
	public int minimum(int i, int j);
}

class SegmentTree implements QueryInterface {
	private int n;
	private int [] lo, hi;
	private int [] min, delta;

	public SegmentTree (int n) {
		this.n = n;
		this.lo = new int[4 * n + 1];
		this.hi = new int[4 * n + 1];
		this.min = new int[4 * n + 1];
		this.delta = new int[4 * n + 1];
		init(1, 0, n - 1);
	}

	public void increment(int a, int b, int val) {
		increment(1, a, b, val);
	}

	public int minimum(int a, int b) {
		return minimum(1, a, b);
	}


	void init (int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;

		if(a == b) return;
		int mid = (a +b) >> 1;
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

	void increment(int i, int a, int b, int val) {
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

	int minimum(int i, int a, int b) {
		if(lo[i] > b || hi[i] < b)
			return Integer.MAX_VALUE;
		if(lo[i] >= a && hi[i] <= b)
			return min[i] + delta[i];

		prop(i);
		int minLeft = minimum(2 * i, a, b);
		int minRight = minimum(2 * i + 1, a, b);
		update(i);

		return Math.min(minLeft, minRight);
	}
};
