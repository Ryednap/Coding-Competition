#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int tt = 0;
	int n, m, c;
	while (scanf("%d %d %d", &n, &m , &c)) {
		if(!n && !m && !c) break;
		
		int ans = 0;
		int current = 0;
		int state[n + 1] = {0};
		int power[n + 1];
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &power[i]);
		}
		
		bool ok = true;
		for(int i = 0; i < m; ++i) {
			int x; scanf("%d", &x);
			if(state[x]) current -= power[x];
			else current += power[x];
			state[x] ^= 1;
			ans = max(ans, current);
			if(current > c) ok = false;
		}
		printf("Sequence %d\n", ++tt);
		if(ok) {
			puts("Fuse was not blown.");
			printf("Maximal power consumption was %d amperes.\n", ans);
		} else puts("Fuse was blown.");
		puts("");
	}
		
	return 0;
}
