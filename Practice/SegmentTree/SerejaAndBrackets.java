import java.io.BufferedReader;
import java.io.IOException;
import java.util.*;
import java.io.InputStreamReader;

public class SerejaAndBrackets  {
	static FastScanner fs = new FastScanner();
	public static void main(String[] args) {
		String s = fs.next();
		SegmentTree st = new SegmentTree(s.length(), s);
		int qq = fs.nextInt();
		while (qq > 0) {
			qq--;
			int l = fs.nextInt() - 1;
			int r = fs.nextInt() - 1;
			System.out.println(st.query(l, r));
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
			return Integer.parseInt(fs.next());
		}

	}
}

class QueryForm {
	public int closed = 0;
	public int open = 0;
	public int complete = 0;
	QueryForm(){}
	QueryForm(int a, int b, int c) {
		this.open = a;
		this.closed = b;
		this.complete = c;
	}

};

class SegmentTree {
	int [] lo, hi;
	QueryForm [] st;
	String str;
	int n;

	public SegmentTree(int n, String str) {
		this.n = n;
		lo = new int[4 * n + 1];
		hi = new int[4 * n + 1];
		st = new QueryForm[4 * n + 1];
		this.str = str;

		init(1, 0, n - 1);
	}

	
	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;

		if(a == b) {
			if(str.charAt(a) == ')') st[i] =  new QueryForm(0, 1, 0);
			if(str.charAt(a) == '(') st[i] =  new QueryForm(1, 0, 0);
			return;
		}

		int m = (a + b) >> 1;
		init(2 * i, a, m);
		init(2 * i + 1, m + 1, b);
		int complete = Math.min(st[2 * i].open, st[2 * i + 1].closed); // closed brackets at this level
		int open = st[2 * i].open + st[2 * i + 1].open - complete;
		int closed = st[2 * i].closed + st[2 * i + 1].closed - complete;
		st[i] = new QueryForm(open, closed, complete + st[2 * i].complete + st[2 * i + 1].complete);
	}

	int query(int l, int r) {
		return query(1, l, r).complete * 2;
	}

	QueryForm query(int i,int a, int b) {
		if(lo[i] > b || hi[i] < a) 
			return new QueryForm(0, 0, 0);
		if(lo[i] >= a && hi[i] <= b) {
			return st[i];
		}

		QueryForm left = query(2*i, a, b);
		QueryForm right = query(2 * i + 1, a, b);
		int complete = Math.min(left.open, right.closed);
		int open = left.open + right.open - complete;
		int closed = left.closed + right.closed - complete;
		return new QueryForm(open, closed, complete + left.complete + right.complete);
	}
}