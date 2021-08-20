#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pvi = pair<vector<int>, int>;
using vi = vector<int>;

#define f first
#define s second

// A little nice question
// Just Go through all the subset and then select all the group and then subtract the extra stuff
// Complexity is (O(n2^n)) although nCk could be accomplished but who cares.

int main() {
	int n, m, tt = 0;
	while(scanf("%d %d", &n, &m)) {
		if(!n && !m) break;
		vi tower(n);
		for(int & x : tower){
			scanf("%d", &x);
		}
		int q; scanf("%d", &q);
		vector<pvi> common;
		for(int i = 0; i < q; ++i) {
			int t; scanf("%d", &t);
			vi v(t);
			for(int & x : v) scanf("%d", &x);
			int x; scanf("%d", &x);
			common.push_back({v, x});
		}
		
		pvi ans = { {}, {0}};
		for(int i = 0; i < (1 << n); ++i) {
			if(__builtin_popcount(i) != m) continue;
			
			vector<int> maybe;
			int total = 0;
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) {
					total += tower[j];
					maybe.push_back(j);
				}
			}
			
			for(int j = 0; j < q; ++j) {
				pvi p = common[j];
				bool ok = false;
				for(int x : p.f) {
					x--;
					if(i & (1 << x)) {
						total -= p.s;
						ok = true;
					}
				}
				if(ok) total += p.s;
			}
			if(total > ans.s) {
				ans.s = total;
				ans.f = maybe;
			} else if(total == ans.s) {
				ans.f = min(ans.f, maybe);
			}
		}
		printf("Case Number  %d\n", ++tt);
		printf("Number of Customers: %d\n", ans.s);
		printf("Locations recommended:");
		for(int x : ans.f) printf(" %d", x + 1);
		puts("\n");
	}
		
	return 0;
}
