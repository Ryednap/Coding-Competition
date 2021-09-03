#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
constexpr int OO = -(int)1e9;

class SegmentTree {
public:
	SegmentTree(int n) { 
		st = vi (4 * n + 1, OO);
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		init (1, 0, n - 1);
	}
	int query (int x) {
		return query (1, 0, x);
	}

	void update (int a, int b) {
		update(1, a, b);
	}

private:
	void init (int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;
		if (a == b)
			return;
		int m = (a + b) >> 1;
		init (2 * i, a, m);
		init (2 * i + 1, m + 1, b);
	}

	int query (int i, int a, int b) {
		if (lo[i] > b || hi[i] < a)
			return OO;
		if (lo[i] >= a && hi[i] <= b)
			return st[i];
		return std :: max(query (2 * i, a, b), query (2 * i + 1, a, b));
	}

	void update (int i, int a, int b) {
		if (lo[i] > b || hi[i] < b)
			return;
		if (lo[i] == hi[i] && lo[i] == b) {
			st[i] = max (st[i], a);
			return;
		}
		update(2 * i , a, b);
		update (2 * i  + 1, a, b);
		st[i] = max (st[2 * i], st[2 * i + 1]);
	}

private:
	vi st;
	vi lo, hi;
};


int main () {
	int n, S;
	scanf ("%d %d", &n, &S);
	vi a(n);
	for (int & x : a) scanf("%d", &x);
	vi pref(n + 1, 0);
	set<int> marker;
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i -1];
		marker.insert (pref[i]);
		marker.insert (pref[i] + S);
	}
	marker.insert (0);
	marker.insert (0 + S);
	int ii = 0;
	unordered_map<int, int> mapper;
	for (auto & el : marker) {
		mapper[el] = ii++;
	}

	int ans = 0;
	SegmentTree st(ii);;

	st.update(n, mapper[pref[n]]);;
	for (int i = n - 1; i >= 0; --i) {
		int x = mapper[S + pref[i]];
		ans = max(ans, st.query(x) - i);
		st.update(i, mapper[pref[i]]);
	}
	printf ("%d\n", ans);
}