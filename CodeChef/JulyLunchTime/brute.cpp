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
		auto divisible = [&] (ll x, int i) {
			if ((x & ((1ll << i) - 1)) == 0)
				return true;
			return false;
		};

		vvi dp (n + 1, vii(64, -1));

		function < int (int, int) > brute = [&] (int i, int k) {
			if(i >= n)
				return 1;
			if(k > 64)
				return 0;
			int & ans = dp[i][k];
			if(ans != -1)
				return ans;

			ll total = 0;
			for (int j = i; j < n; ++j) {
				total ^= a[j];
			}

			ans = 0;
			ll front = 0;
			for (int j = i; j < n; ++j) {
				total ^= a[j];
				front ^= a[j];
				if(divisible(front, k)) ans = Add(ans, brute(j + 1, k + 1));
			}
			return ans;
		};

		printf("%d\n", brute(0, 0));
	}
	return 0;
}