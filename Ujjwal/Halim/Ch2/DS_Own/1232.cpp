#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<pair<int,int>,int>;
using vpi = vector<pii>;
using vi = vector<int>;

#define f first
#define s second

class SegmentTree {
public:
	const int n = (int)1e5;
	SegmentTree() {
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1);
		
		init(1, 0, n - 1);
	}
	void update(int l, int r, int h, int c) {
		update(1, l, r, h, c);
	}
	pii query(int a) {
		return query(1, a);
	}
	void dbg() {
		debug() << owo(st);
	}

private:
	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;
		if(a == b)
			return;
		int m = (a + b) >> 1;
		init(2 * i, a, m);
		init(2 * i + 1, m + 1, b);
	}
	pii Merge(const pii & a, const pii & b) {
		if(b.f.s < a.f.s) { // a came later
			if(b.f.f < a.f.f) // a height big
				return pii({a.f.f, a.f.s}, b.s + a.s);
			else return b;

		} else {
			if(b.f.f > a.f.f) // b came later and b is big
				return pii({b.f.f, b.f.s}, a.s + b.s);
			else 
				return a;
		}
	}

	void prop(int i) {
		st[2 * i] = Merge(st[2 * i], st[i]);
		st[2 * i + 1] = Merge(st[2 * i + 1], st[i]);
		st[i] = pii({0, 0}, 0);
	}

	void update(int i, int a, int b, int h, int c) {
		if(lo[i] > b || hi[i] < a)
			return;
		if(lo[i] >= a && hi[i] <= b) {
			st[i] = Merge(st[i], pii({h, c} , 1));
			return;
		}
		prop(i);
		update(2 * i,  a, b, h, c);
		update(2 * i + 1, a, b, h, c);
	}

	pii query(int i, int a) {
		if(lo[i] > a || hi[i] < a)
			return pii({0, 0}, 0);
		if(lo[i] >= a && hi[i] <= a)
			return st[i];

		prop(i);
		pii left = query(2 * i , a);
		pii right = query(2 * i + 1, a);
		if(left.f.f != 0)
			return left;
		return right;
	}

private:
	vi lo, hi;
	vpi st;
};

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		SegmentTree st;
		for(int i = 1; i <= n; ++i) {
			int l, r, h;
			scanf("%d %d %d", &l, &r, &h);
			--l, --r;
			st.update(l, r - 1, h, i);
		}

		int answer = 0;
		for(int i = 0; i < st.n; ++i) {
			auto p = st.query(i);
			answer += p.s;
		}
		printf("%d\n", answer);
	}
	return 0;
}
