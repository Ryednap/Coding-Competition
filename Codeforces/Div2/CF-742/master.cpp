#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
using vi = vector<ll>;
class SegmentTree {
public:
	SegmentTree(int n, vi a) {
		ar = a;
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1);
		init(1, 0, n - 1);
	}

	ll query (int a, int b) {debug() << owo(st); return query(1, a, b);}
	void update(int a, int b) {update(1, a, b);}

private:
	void init (int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;
		if (a == b){
			st[i] = ar[a];
			return;
		}
		int m = (a + b) >> 1;
		init (2 * i, a, m);
		init (2 * i + 1, m + 1, b);
	}

	ll query (int i, int a, int b) {
		if (lo[i] > b || hi[i] < a) return 0;
		if (lo[i] >= a && hi[i] <= b) return st[i];
		return query(2 * i, a, b) + query(2 * i + 1, a, b);
	}
	void update (int i, int a, ll b) {
		if (lo[i] > a || hi[i] < a) return ;
		if (lo[i] >= a && hi[i] <= a) {
			st[i] = b;
			return;
		}
		update(2 * i,a , b);
		update(2 *i + 1 , a, b);
		st[i] = st[2 * i] + st[2 * i + 1];
	}

private:
	vi lo, hi;
	vi st, ar;
};



int main () {
	int n, q;
	scanf ("%d %d", &n, &q);
	vi a(n);
	for (ll & x : a) {
		scanf ("%lld",&x);
	}

	SegmentTree st(n,a );
	st.update(0, 1);
	int curr = 1;
	vector<int> b(n);
	b[0] = curr;
	for (int i = 1; i < n; ++i) {
		if (a[i] >= a[i -1]) ++curr;
		else curr = 1;
		a[i] = curr;
		ll value = (1ll * (curr * (curr + 1)) / 2) - (1ll * ((curr - 1) * curr)) / 2;
		st.update(i, value);
	}

	while (q--) {
		int c, l,  r;
		scanf ("%d %d %d", &c, &l, &r);
		if (c == 2) {
			 printf ("%lld\n", st.query(l - 1, r - 1));
		} else {
			--l;
			ll x = r;
			if (l - 1 && a[l - 1] <= x && a[l] == 1) {
				ll value = 
				st.update(l, )
			}
		}
	}
	return 0;
}