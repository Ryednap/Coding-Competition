import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class KQuery {
	static FastScanner fs = new FastScanner();
	public static void main(String[] args) {
		int n = fs.nextInt();
		Pair [] arr = new Pair[n];
		for(int i = 0; i < n; ++i) {
			int x = fs.nextInt();
			arr[i] = new Pair(x, i);

		}
		Arrays.sort(arr);

		int qq = fs.nextInt();
		QueryForm [] Query = new QueryForm[qq];
		for(int i = 0; i < qq; ++i) {
			int l = fs.nextInt();
			int r = fs.nextInt();
			int k = fs.nextInt();
			Query[i] = new QueryForm(k, l, r, i);
		
		}
		Arrays.sort(Query);
		
		SegmentTree st = new SegmentTree(n);
		int answer [] = new int[qq];

		for(int i = 0, j = 0; i < qq; ++i) {
			int k = Query[i].k;
			int l = Query[i].l - 1;
			int r = Query[i].r - 1;
			int index = Query[i].i;
			while (j < n && arr[j].first <= k) {
				st.update(arr[j].second);
				++j;
			}
			answer[index] = st.query(l, r);
		}

		for(int i = 0; i < qq; ++i) {
			System.out.println(answer[i]);
		}
	}

	static class FastScanner{
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
	}
}

class Pair implements Comparable <Pair> {
	public int first;
	public int second;
	public Pair(int a, int b) {
		this.first = a;
		this.second = b;
	}
	@Override
	public int compareTo(Pair ob) {
		return this.first - ob.first;
	}
}

 class QueryForm implements Comparable <QueryForm> {
	public int k;
	public int l;
	public int r;
	public int i;

	QueryForm(){}
	QueryForm(int a, int b, int c, int d) {
		this.k = a;
		this.l = b;
		this.r = c;
		this.i = d;
	}

	@Override
	public int compareTo(QueryForm ob) {
		return this.k - ob.k;
	}
}

class SegmentTree {
	int [] lo, hi;
	int [] st;

	public SegmentTree(int n) {
		lo = new int[4 * n + 1];
		hi = new int[4 * n + 1];
		st = new int[4 * n + 1];
		init(1, 0, n - 1);
	}

	public void update(int x) {
		update(1, x);
	}

	public int query(int l, int r) {
		return query(1, l, r);
	}

	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;

		if(a == b) {
			st[i] = 1;
			return;
		}
		int mid = (a + b) >> 1;
		init(2 * i, a, mid);
		init(2 * i + 1, mid + 1, b);
		st[i] = st[2 * i] + st[2 * i + 1];
	}



	void update(int i, int a) {
		if(lo[i] > a || hi[i] < a)
			return;
		if(lo[i] == a && hi[i] == a) {
			st[i] = 0;
			return;
		}

		update(2 * i, a);
		update(2 * i + 1, a);
		st[i] = st[2 * i] + st[2 * i + 1];
	}

	int query(int i, int a, int b) {
		if(lo[i] > b || hi[i] < a) 
			return 0;
		if(lo[i] >= a && hi[i] <= b) 
			return st[i];

		return query(2 * i, a, b) + query(2 * i + 1, a, b);
	}
}