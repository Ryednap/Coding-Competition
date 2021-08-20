#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
using pii = pair<ll, ll>;
using vl = std::vector<ll>;
using vi = std::vector<int>;
#define f first
#define s second

class SegmentTree {
public:
	SegmentTree(int n) {
		st.resize(4 * n + 1);
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		fill(st.begin(), st.end(), pii(-1, -1));
		init(1, 0, n - 1);
	}

	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;
		if(a == b)
			return;
		int m = (a + b) >> 1;
		init(i << 1, a, m);
		init(2 * i + 1, m + 1, b);
	}

	pii query(int a, int b) {
		return query(1, a, b);
	}
	void update(int i, pii a) {
		update(1, i, a);
	}

private:
	pii getMax(pii a, pii b) {
		if(a.f == b.f) 
			return b.s > a.s ? b : a;
		return b.f > a.f ? b : a;
	}
	pii query (int i, int a, int b) {
		if(lo[i] > b || hi[i] < a)
			return pii(-1, -1);
		if(lo[i] >= a && hi[i] <= b)
			return st[i];
		pii left = query(i << 1, a, b);
		pii right = query(2 * i + 1, a, b);
		return getMax(left, right);
	}

	void update(int i, int a, pii b) {
		if(lo[i] > a || hi[i]  < a)
			return;
		if(lo[i] >= a && hi[i] <= a) {
			st[i] = getMax(st[i], b);
			return;
		}
		update(i << 1, a, b);
		update(2 * i + 1, a, b);
		st[i] = getMax(st[i << 1], st[2 * i + 1]);
	}
private:
	vector<pii> st;
	vi lo, hi;
};


int main() {
	ll x;
	vl v;
	while (scanf("%lld", &x) != EOF) {
		v.push_back(x);
	}
	const int n = (int) v.size();
	SegmentTree st(2 * n + 1);
	vl temp = v;

	sort (temp.begin(), temp.end());
	map<ll, int> mapper;

	for (int i = 0; i < n; ++i) {
		mapper[temp[i]] = i;
	}

	vi par(n);
	vi dp(n);
	for (int i = 0; i < n; ++i) {
		pii maxi = st.query(0, mapper[v[i]] - 1);
		if(maxi.f != -1) {
			dp[i] = maxi.f + 1;
			par[i] = maxi.s;
		} else {
			dp[i] = 1;
		}

		st.update(mapper[v[i]], pii(dp[i], i));
	}

	int ans = 0, where = -1;;
	for (int i = 0; i < n; ++i) {
		if(ans <= dp[i])
			ans = dp[i], where = i;
	}	

	assert (where != -1);
	vl seq;
	while (where != par[where]) {
		seq.push_back(v[where]);
		where = par[where];
	}
	seq.push_back(v[where]);
	reverse(seq.begin(), seq.end());
	printf("%d\n", ans);
	puts("-");
	for (auto & x : seq)
		printf("%lld\n", x);
	return 0;
}
