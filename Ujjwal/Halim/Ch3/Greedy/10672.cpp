#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using pqi = priority_queue<pii>;
#define f first
#define s second

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		vector<vi> edges(n + 1);
		vi marbes[n + 1];
		
		for(int i = 0; i < n; ++i) {
			int v, x, d;
			scanf("%d %d %d", &v, &x, &d);
			marbels[v] = x;
			for(int j = 0; j < d; ++j) {
				int u;
				scanf("%d", &x);
				edges[v].push_back(u);
				edegs[u].push_back(v);
			}
		}
		
		int ans = 0;
		function <void(int, int, int)> Dfs = [&] (int node, int par, int h) {
			
			if((int)edges[node] == 1) { // reached root
				
				
			}
			
			for(int child : edges[node]) {
				if(child != par) {
					Dfs(child, node, h + 1, q);
				}
			}
		
		Dfs(1, pqi());
		Dfs(1, pqi());
		
		printf("%d\n",ans);
	}
			
	return 0;
}
