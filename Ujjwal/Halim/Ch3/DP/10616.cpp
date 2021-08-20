#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
using vll = vector<long long>;

int main() {
	int n, q;
	int tt = 0;
	while (scanf("%d %d", &n, &q) && n) {
		vi arr(n);
		for(int & x : arr) {
			scanf("%d", &x);
		}
		printf("SET %d:\n", ++tt);
		int tc = 0;
		while (q--) {
			int m, d;
			scanf("%d %d", &d, &m);
			
			vector<vector<vll>> dp(n, vector<vll> (m + 1, vll(d + 1, -1)));
			auto Operation = [&] (long long a, int b, int c) {
				return ((a + b)%c + c)%c;
			};
			function < long long (int , int, int) > Brute = [&] (int i, int j, int k) {
				if(j == m) return k == 0 ? 1LL : 0LL;
				if(i == n) return 0LL;
				long long & ans = dp[i][j][k];
				if(ans != -1) return ans;
				
				return ans = Brute(i + 1, j, k) + Brute(i + 1, j + 1, Operation(k, arr[i], d));
			};
			
			printf("QUERY %d: %lld\n", ++tc, Brute(0, 0, 0));
		}
	}
	return 0;
}
