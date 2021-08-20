#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// One of the best questions to solve

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int L, n;
		scanf("%d %d", &L, &n);
		int maxi = 0, mini = 0;
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			mini = max(mini, min(x, L - x));
			maxi = max(maxi, max(x, L - x ));
		}
		
		printf("%d %d\n", mini, maxi);
	}
	return 0;
}
