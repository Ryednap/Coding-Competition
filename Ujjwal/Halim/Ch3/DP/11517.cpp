#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int nax = (int)3e4 + 100;
const int OO = (int)1e9;

// Mistake : in question it's not mentioned explicitly that we have to use each coin once.


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int total, n;
		scanf("%d %d", &total, &n);
		
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		vector<int> dp(nax, OO);
		dp[0] = 0;
		for(int j = 0; j < n; ++j) {
			for(int i = nax - 1; i >= 0; --i) {
				if(i + arr[j] < (int)dp.size()) dp[i + arr[j]] = min(dp[i + arr[j]], dp[i] + 1);
			}
			
		}
		
		int where = -1;
		for(int i = total; i < (int)dp.size(); ++i) {
			if(dp[i] != OO) {
				where = i;
				break;
			}
		}
		assert(where != -1);
		printf("%d %d\n", where, dp[where]);
	}
	return 0;
}
