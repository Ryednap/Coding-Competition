#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int nax = 1e4 + 1;

int main() {
	int qq;
	scanf("%d", &qq);
	
	int dp[nax];
	for(int i = 0; i < nax; ++i) {
		dp[i] = (int)1e9;
	}
	
	dp[0] = 0;
	for(int i = 1; i * i < nax; ++i) {
		int x = i * i;
		for(int j = 0; j + x < nax; ++j) {
			dp[j + x] = min(dp[j + x], dp[j] + 1);
		}
	}
	
	while (qq--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	
	return 0;
}
