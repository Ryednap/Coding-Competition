#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int NAX = 7489 + 10;

int main() {
	vector<long long> dp(NAX, 0);
	vector<int> coins = {1, 5, 10, 25, 50};
	dp[0] = 1;
	for(int x : coins) {
		for(int j = 0; j < NAX - x; ++j) {
			dp[j + x] += dp[j];
		}
	}
	
	
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", dp[n]);
	}
	
	
	return 0;
}
