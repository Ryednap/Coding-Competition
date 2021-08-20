#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n ^ 2) complexity
// O(n) can be achieved by using variation of kadane's algorithm

int main() {
	int n, tt = 0;
	while (scanf("%d",&n) != EOF) {
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			long long curr = 0;
			for(int j = i; j < n; ++j) {
				if(curr == 0) curr = arr[j];
				else curr *= arr[j];
				ans = max(ans, curr);
			}
			
		}
		printf("Case #%d: The maximum product is %lld.\n", ++tt, ans);
		puts("");
	}
	return 0;
}
