#include <iostream>
#include <functional>
#include <cstdio>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
constexpr ll OO = (ll)1e14;

int main () {
	int tt; scanf ("%d", &tt);
	while (tt--) {
		int n, K;
		scanf ("%d %d", &n, &K);
		using vi = vector<ll>;
		using vvi = vector<vi>;
		using vvvi = vector<vvi>;

		vvi cost(n, vi(n));
		vector<string> mat(n + 1);
		for (int i = 0 ; i < n; ++i) {
			cin >> mat[i];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf ("%lld", &cost[i][j]);
			}
		}
		
		vvvi dp(n, vvi(n, vi(K + 2, -1)));
		function < int (int, int, int) > solve = [&] (int i, int j, int k) {
			if (i == n - 1 && j == n - 1) {
				return cost[i][j];
			}
			ll & ans = dp[i][j][k];
			if (ans != -1)
				return ans;
			ans = -OO;
			if (i + 1 < n) {
				if ((k == 0 || k == K) && mat[i + 1][j] != '#')
					ans = max(ans, solve(i + 1, j, k) + cost[i][j]);
				if (k < K) ans = max(ans, solve(i + 1, j, k + 1) + cost[i][j]);
			}
			if(j + 1 < n) {
				if ((k == 0 || k == K) && mat[i][j + 1] != '#')
					ans = max(ans, solve(i, j + 1, k) + cost[i][j]);
				if (k < K) ans = max(ans, solve(i, j + 1, k + 1) + cost[i][j]);
			}
			return ans;
		};
		ll ans = solve(0, 0, 0);
		if (ans < 0) puts("-1");
		else printf ("%lld\n", ans);
	}
}