#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int NAX = 10;

int main() {
	vector<int> coins = {1, 2, 3, 4, 5};

	vector<int> dp(NAX, 0);
	dp[0] = 1;
	// coin change with repeatation and permutation allowed.
	for(int i = 0; i < NAX; ++i) {
		for (int c : coins) {
			if(c + i < NAX) dp[i + c] += dp[i];
		}
	}

	debug() << owo(dp);

	dp = vector<int> (NAX,  0);
	dp[0] = 1;

	// coin change with repeatation but no permutation allowed
	for(int c : coins) {
		for(int i = 0; i < NAX; ++i) {
			if(i + c < NAX) dp[i + c] += dp[i];
		}
	}

	debug() << owo(dp);

	dp = vector<int> (NAX, 0);
	dp[0] = 1;

	// coin change witout repeatation and no permutation.
	for(int c : coins) {
		for (int i = NAX - c - 1; i >= 0; --i) {
			dp[i + c] += dp[i];
		}
	}

	debug() << owo(dp);

}