#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int nax = 100;

int main() {
	vector<vector<int>> dp(nax + 1, vector<int> (nax + 1, 0));
	dp[0][0] = dp[0][1] = 1;

	for (int i = 0; i < nax; ++i) {
		for(int j = i; j < nax; ++j) {
			for(int k = 0; k <= nax; ++k) {
				if(i + j < nax) dp[i + j][k + 1] += dp[i][k];
			}
		}
	}
	
	//debug() << owo(dp);
	
	int n, k;
	while (scanf("%d %d", &n, &k)) {
		if(!n && !k) break;
		
		if(k > n) puts("0");
		else printf("%d\n", dp[n][k] + 1);
	}
	
	return 0;
}
