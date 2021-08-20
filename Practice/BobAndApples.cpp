#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vi v(n), p(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &v[i], &p[i]);
		}
		vector<vvi> dp(n + 1, vvi(m + 1, vi(2, -1)));
		const int OO = (int)1e9;
		function < int (int, int, int) > brute = [&] (int i, int j, int k ) {
			if(j > m) return -OO;
			if(i == n)
				return 0;

			int & ans = dp[i][j][k];
			if(ans != -1) return ans;
			ans = max(brute(i + 1, j, k), brute(i + 1, j + p[i], k) + v[i]);
			if(k) ans = max(ans, brute(i + 1, j + p[i]/2, 0) + v[i]);
			return ans = max(ans, 0);
		};

		printf("%d\n", brute(0, 0, 1));
	}

	return 0;
}