#include <bits/stdc++.h>

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		long long pref[n + 1] = {0};
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			pref[i + 1] = x + pref[i];
		}
		
		int q;
		scanf("%d", &q);
		while (q--) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%lld\n", pref[r] - pref[l - 1]);
		}
	}
	return 0;
}
