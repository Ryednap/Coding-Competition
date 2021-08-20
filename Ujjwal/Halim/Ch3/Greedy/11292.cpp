#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int n, m;
	while (scanf("%d %d", &n, &m)) {
		if(!n && !m) break;
		int Dragon[n], Knight[m];
		for(int i = 0; i < n; ++i) {
			scanf("%d",&Dragon[i]);
		}
		for(int i = 0 ; i < m; ++i) {
			scanf("%d", &Knight[i]);
		}
		
		if(n > m) {
			puts("Loowater is doomed!");
			continue;
		}
		
		sort(Dragon, Dragon + n);
		sort(Knight, Knight + m);
		
		bool ok = true;
		int ans = 0;
		for(int i = 0, j = 0; i < n; ++i) {
			while (j < m && Dragon[i] > Knight[j]) ++j;
			if(j == m || Dragon[i] > Knight[j]) {
				ok = false;
				break;
			}
			
			ans += Knight[j++];
		}
		
		if(ok) printf("%d\n", ans);
		else puts("Loowater is doomed!");
	}
		
	return 0;
}
