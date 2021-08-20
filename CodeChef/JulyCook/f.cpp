#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using piii = pair<int, pii>;
#define f first
#define s second



int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) { 
		 int n, k;
		 scanf("%d %d", &n, &k);
		 vi a(n);
		 for(int i = 0;i < n; ++i) {
		 	scanf("%d", &a[i]);
		 }

		vector<vector<piii>> Edges(n);
		 for(int i = 0; i < n - 1; ++i) {
		 	for(int j = i + 1; j < n; ++j) {
		 		if(a[i] == a[j]) {
		 			Edges[i].push_back({j, {0, 1}});
		 			break;
		 		}
		 	}
		 	Edges[i].push_back({i + 1, {0, 0}});
		 	Edges[i].push_back({i + 1, {1, 1}});
		}
		
		vector<vi> dp(n + 1, vi(k + 1, -1));
		function < int (int, int) > dfs = [&] (int node, int cost) {
			int & ans = dp[node][cost];
			if(ans != -1)
				return ans;
			ans = 1;
			for(piii child : Edges[node]) {
				if(cost + child.s.f <= k)
					ans = max(ans, dfs(child.f, cost + child.s.f) + child.s.s);
			}
		//	debug() << owo(node) owo(a[node]) owo(cost) owo(ans);
			return ans;
		};
		int ans = 1;
		for(int i = 0; i < n; ++i) {
			ans = max(ans, dfs(i, 0));
		}
		printf("%d\n", ans);
	}
	return 0;
}