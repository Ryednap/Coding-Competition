#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
const ll OO = 1e14;


int main() {
	int n, m;
	scanf("%d %d",&n, &m);
	ll dp[n + 1][n + 1];
	for(int i = 0 ; i < n; ++i) 
		for(int j = 0 ; j < n; ++j) {
			if(i == j) dp[i][j] = 0;
			else dp[i][j] = OO;
		}

	for(int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d" ,&a, &b, &c);
		--a, --b;
		dp[a][b] = c;
	}


	ll answer = 0;
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				if(dp[i][j] < OO) {
					answer += dp[i][j];
				}
			}
		}
	}

	
	printf("%lld\n", answer);
	return 0;
}