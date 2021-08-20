#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int K;
#define FOR(a, b) for(int a = b; a < K; ++a)

int main() {
	scanf("%d", &K);
	while (K) {
		int arr[K];
		for (int i = 0; i < K; ++i) {
			scanf("%d", &arr[i]);
		}
		
		FOR(i, 0) FOR(j, i + 1) FOR(k, j + 1) FOR(l, k + 1) FOR(m, l + 1) FOR(n, m + 1) {
			printf("%d", arr[i]);
			for(int a : {j, k, l, m, n}) {
				printf(" %d", arr[a]);
			}
			puts("");
		}
		scanf("%d", &K);
		if(K)puts("");
	}
	return 0;
}
