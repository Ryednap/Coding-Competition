#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define s second
#define f first

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m)) {
		if(!n && !m) break;
		vector<pii> edges[n + 1];
		for(int i = 0 ; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			edges[a].push_back({a, b});
			edges[b].push_back({b, a});
		}
		
		map<pii, bool> used;
		vector<int> vis(n, false);
		int answer = 0;
		
		function < void(int, int) > dfs = [&] (int node, int d) {
			answer = max(answer, d);
			vis[node] = true;
			for(auto p : edges[node]) {
				if(!used[p]) {
					used[p] = used[{p.s, p.f}] = true;
					dfs(p.s, d + 1);
					used[p] = used[{p.s, p.f}] = false;
				}
			}
		};	
		
		for(int i = 0; i < n; ++i) {
				dfs(i, 0);
		}
		
		printf("%d\n", answer);
	}
		
	return 0;
}
