#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * This is bi-partite matching problem. There are two ways to think in greedy.
 * Either both will same order or opposite.
 * There is a counter for same order . 10 12 and 12 14 with 25 as d
 * So obiviously both must be of opposite order.
 */

int main() {
	int n, d, r;
	while (scanf("%d %d %d", &n, &d, &r)) {
		if(!n && !d && !r) break;
		int A[n], B[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &A[i]);
		}
		for(int j = 0; j < n; ++j) {
			scanf("%d", &B[j]);
		}
		
		sort(A, A + n);
		sort(B, B + n);
		reverse(A, A + n);
		
		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			if(A[i] + B[i] > d) {
				ans += (A[i] + B[i] - d) * (long long)r;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
