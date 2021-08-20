#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

// Note don't go with the 6 attempts 4 were made in a single click and 1 was CE and final was a WA and then accepted. The problem was rounding error
// and missing 500 cents coin.

const int NAX = 3e4 + 100;

int main() {
	vector<long long> dp(NAX, 0);
	vector<int> coins = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	dp[0] = 1;
	for(int x : coins) {
		for(int j = 0; j < NAX - x; ++j) {
			dp[j + x] += dp[j];
		}
	}
	
	
	double amount;
	while (scanf("%lf", &amount)) {
		int n = round(amount * 100);
		//debug() << owo(n) owo(amount);
		if(!n) break;
		printf("%6.2f%17lld\n", amount, dp[n]);
	}
	
	
	return 0;
}
