#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		vector<array<int, 2>> arr(n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 2; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		sort(arr.begin(), arr.end(), [](array<int, 2> &a, array<int, 2> &b) {
			if(a[0] == b[0]) return a[1] < b[1];
			else return a[0] < b[0];
		});
		
		int dp[n] = {0};
		for(int i = 0; i < n; ++i) {
			dp[i] = 1;
			for(int j = 0; j < i; ++j) {
				if(arr[i][0] >= arr[j][0] && arr[i][1] >= arr[j][1])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		
		printf("%d\n", *max_element(dp, dp + n));
	}
	puts("*");
	
	
	return 0;
}
