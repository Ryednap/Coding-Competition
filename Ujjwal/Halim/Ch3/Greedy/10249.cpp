#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

// O(n ^ 2) algorithm

int main() {
	int n, m;
	while (scanf("%d %d",&n, &m)) {
		if(!n && !m) break;
		int b[m];
		pii a[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i].f);
			a[i].s = i;
		}
		for(int j = 0; j < m; ++j) {
			scanf("%d", &b[j]);
		}
		
		sort(a, a + n);
		reverse(a, a + n);
		
		vector<int> ans[n];
		
		bool ok = true;
		for(int i = 0; i < n && ok; ++i) {
			int req = a[i].f;
			for(int j = 0; j < m && req; ++j) {
				if(b[j] > 0) {
					--req;
					--b[j];
					ans[a[i].s].push_back(j);
				}
			}
			if(req) ok = false;
		}
		
		if(ok) {
			puts("1");
			for(int i = 0; i < n; ++i) {
				printf("%d", ans[i][0] + 1);
				for(int j = 1; j < (int)ans[i].size(); ++j) {
					printf(" %d", ans[i][j] + 1);
				}
				puts("");
			}
				
		} else puts("0");
	}
		
	return 0;
}
