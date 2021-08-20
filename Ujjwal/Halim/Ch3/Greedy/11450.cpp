#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int amount, n;
		scanf("%d %d", &amount, &n);
		vector<vi> arr(n);
		int mini = 0;
		for(int i = 0; i < n; ++i) {
			int m; scanf("%d", &m);
			arr[i].resize(m);
			int which = (int)1e0;
			for(auto & x : arr[i]) {
				scanf("%d", &x);
				which = min(which, x);
			}
			mini += which;
		}
		
		vector<vi> dp(n + 10, vi(amount + 100, -1));
		for(int i = 0; i < n; ++i) {
			dp[i][0] = 0;
			for(int j = amount; j >= 1; --j) {
				for(int k = 0; k < (int)arr[i].size(); ++k) {
					if(j >= k && dp[i][j] != -1) {
						dp[i + 1][j - arr[i][k]] = max(dp[i + 1][j - arr[i][k]], dp[i][j] + arr[i][k]);
					}
				}
			}
		}
		
		int ans = *max_element(dp[n].begin(), dp[n].end());
				 
		printf("%d\n",ans);
	}
	return 0;
}
