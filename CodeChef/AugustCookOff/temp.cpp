#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

struct FastScanner {
	FastScanner () {}
	std :: string next () {
		std :: string s;
		std :: cin >> s;
		return s;
	}
	int nextInt () {
		int x;
		scanf ("%d", &x);
		return x;
	}
	long long  nextLong () {
		long long x;
		scanf ("%lld", &x);
		return x;
	}
	float nextFloat() {
		float x;
		scanf ("%f", &x);
		return x;
	}
};

FastScanner fs;
int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 0; tt < qq; ++tt) {
		int n = fs.nextInt();
		int k = fs.nextInt();
		int x = fs.nextInt();
		vector<int> v(n);
		for (int & i : v) {
			i = fs.nextInt();
		}
		using ll = long long;
		vector<vector<ll>> dp (n, vector<ll> (n / 2 + 2, -1));
		vector<ll> pref(n + 1);
		for (int i = 1; i <= n; ++i) {
			pref[i] = pref[i - 1] + v[i- 1];
		}
		function < ll (int, int) > solve = [&] (int i , int j) -> ll {
			int last = n - 1 - (k - j);
			if (i > last)
				return 0;
			if (i == last)
				return v[i];
			if (j == 0)
				return pref[last + 1] - pref[i];
			ll & ans = dp[i][j];
			if (ans != -1)
				return ans;
			ans = 2e18L;
			ans = min (ans, solve(i + 1, j) + v[i]);
			if (j)  ans = min(ans, solve(i + 1, j - 1) + x);
			return ans;
		};
		printf("%lld\n", solve(0, k));
	}
	return 0;
}