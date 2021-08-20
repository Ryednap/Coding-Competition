#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(sqrt(k)) complexity

/*
 * Proof :- we will iterate upto k terms . In each iteration the terms increases by d * i => d * i (i + 1) / 2 = k
 * The worst case is when d = 1. then i = O(sqrt(k)).
 */

const int nax = (int)1e4;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq-- ) {
		int k;
		scanf("%d", &k);
		int deg[k + 1];
		for(int i = 0; i <= k; ++i) {
			scanf("%d", &deg[i]);
		}
		
		int d, K;
		scanf("%d %d", &d, &K);
		
		auto F = [&] (int n) {
			long long total = 0;
			for(int i = 0; i <= k; ++i) {
				total += deg[i] * pow((long long)n, i);
			}
			return total;
		};
		
		
		int terms = 0;
		long long ans = -1;
		for(int i = 1; i <= nax; ++i) {
			if(terms >= K) {
				ans = F(i - 1);
				break;
			} else terms += d * i;
		}
		assert(ans != -1);
		printf("%lld\n", ans);
	}
			
	return 0;
}
