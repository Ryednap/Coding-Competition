#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n ^ 2) as normal
// O(nlogn) after pruning;

int main() {
	int n, qq;
	scanf("%d", &qq);
	while (qq--) {
		scanf("%d", &n);
		long long ans = 1e18L;
		for(int i = 1; i <= n; ++i) {
			for(int j = i; j * i <= n; ++j) {
				long long y = 1LL * i * j;
				if(n % y == 0) {
					int k = n / y;
					ans = min(ans, 2LL * (i * j + j * k + k * i));
				} 
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
