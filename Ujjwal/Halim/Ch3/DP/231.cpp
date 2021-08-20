#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main() {
	int x, tt = 0;
	scanf("%d", &x);
	while (x != -1) {
		vector<int> v;
		v.push_back(x);
		while (scanf("%d", &x) && x != -1) {
			v.push_back(x);
		}
		//debug() << owo(v);
		const int n = (int)v.size();
		int dp[n + 1] = {0};
		for(int i = 0; i < n; ++i) {
			dp[i] = 1;
			for(int j = 0; j < i; ++j) {
				if(v[i] <= v[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		
		printf("Test #%d:\n", ++tt);
		printf("  maximum possible interceptions: %d\n", *max_element(dp, dp + n + 1));
		scanf("%d", &x);
		if(x != -1) puts("");
	}
	return 0;
}
