#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
const int OO = (int)1e6;

int main() {
	int n, m;
	while (scanf("%d %d", &m, &n) != EOF) {
		vi p(n), f(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &p[i], &f[i]);
		}
		
		# warning "keep the m + x where x > 200 else RTE"
		vector<vi> dp(n, vi(m + 400, -1));
		
		# warning "If error then 2000 is inclusive"
		auto F = [&] (int x) {
			if(x > 2000) return x - 200;
			return x;
		};
		
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(F(j) > m) return -OO;
			if(i == n) return 0;
			
			int & ans = dp[i][j];
			if(ans != -1) return ans;
			
			return ans = max(
					Brute(i + 1, j),
					Brute(i + 1, j + p[i]) + f[i]
				);
		};
		
		printf("%d\n", Brute(0, 0));
	}
	
	return 0;
}
