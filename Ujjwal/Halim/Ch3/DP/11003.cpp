#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;

const int OO = (int)1e4;

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		vi w(n), m(n);
		int maxi = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &w[i], &m[i]);
			maxi = max(m[i], maxi);
		}
		
		vector<vi> dp(n, vi(maxi + 100, -1));
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(j < 0) return -OO;
			if(i == n) return 0;
			
			int & ans = dp[i][j];
			if(ans != -1) return ans;
			
			# warning
			int here = (j == (maxi + 99)) ? m[i] : min(j - w[i], m[i]);
			ans = max(
				Brute(i + 1, j),
				Brute(i + 1, here) + 1);
			
			return ans;
		};
		
		printf("%d\n", Brute(0, maxi + 99));
	}
	
	return 0;
}
