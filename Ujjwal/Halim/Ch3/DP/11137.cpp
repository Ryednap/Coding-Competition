#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int NAX = 10000 + 10;
const int FAX = 9261;

int main() {
	vector<long long> dp(NAX, 0);
	dp[0] = 1;
	for(int i = 1; i * i * i <= FAX; ++i) {
		for(int j = 0; j < NAX - i * i * i; ++j) {
			dp[j + i * i * i] += dp[j];
		}
	}
	
	
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", dp[n]);
	}
	
	
	return 0;
}
