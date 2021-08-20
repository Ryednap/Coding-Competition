#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int NAX = 30000 + 10;

int main() {
	int n;
	long long dp[NAX];
	memset(dp, 0, sizeof(dp));
	int coins [] = {1, 5, 10, 25, 50};
	dp[0] = 1;
	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < NAX ; ++j) {
			if(j + coins[i] < NAX) dp[j + coins[i]] += dp[j];
		}
	}
	while (scanf("%d", &n) != EOF) {
		if(dp[n] > 1) printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
		else printf("There is only %lld way to produce %d cents change.\n", dp[n], n);
	}
	return 0;
}
