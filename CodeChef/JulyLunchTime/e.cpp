#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
using vi = std::vector<ll> ;
using pii = pair<ll, ll>;
using vii = vector<int>;
using vvi = vector<vii>;
using vvvi = vector<vvi>;

#define f first
#define s second


const int mod = (int)1e9 + 7;
int Add (int a, int b) {
	return (a + b) % mod;
}

class SegmentTree {
public:
	SegmentTree(int n, vi ar) {
		st.resize(4 * n + 1);
		arr= ar;
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);

		init(1, 0, n - 1);
	}	

	ll query(int a, int b) {
		if(a > b)
			return -1;
		return query(1, a, b);
	}

private:
	void init (int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;
		if(a == b) {
			st[i] = arr[a];
			return;
		}
		int m = (a + b) >> 1;
		init(2 * i, a, m);
		init(2 * i + 1, m + 1, b);
		st[i] = st[2 * i] ^ st[2 * i + 1];
	}

	ll query (int i, int a, int b) {
		if(lo[i] > b || hi[i] < a)
			return 0;
		if(lo[i] >= a && hi[i] <= b)
			return st[i];

		ll left = query(2 * i, a, b);
		ll right = query(2 * i + 1, a, b);
		return left ^ right;
	}

private:
	vi st, arr ;
	vii lo, hi;
};

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		vi a(n);
		for (auto &x : a) {
			scanf("%lld", &x);
		}
		SegmentTree st(n, a);
		auto divisible = [&] (ll x, int i) {
			if(x < 0)
				return true;
			if ((x & ((1ll << i) - 1)) == 0)
				return true;
			return false;
		};

		vvvi dp (n + 1, vvi (n + 1, vii(64, -1)));
		function < int (int, int, int) > brute = [&] (int i,int j, int k) {
			if(i >= n)
				return i == j ? 1 : 0;
			if(k > 63)
				return 0;
			int & ans = dp[i][j][k];
			if(ans != -1)
				return ans;

			bool left = divisible(st.query(j, i), k);
			ll l = 0;
			ll r = brute(i + 1, j, k);
			if(left){
				l = brute(i + 1, i + 1, k + 1);
			}
			ans = 0;
			return ans = Add(l, r);
		};

		printf("%d\n", brute(0, 0, 0));
	}
	return 0;
}