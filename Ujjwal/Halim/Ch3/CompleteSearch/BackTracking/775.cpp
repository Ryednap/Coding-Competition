#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// No need to search here and there. Just do the DFS. Don't mess with this. If the graph is fully connected then we have Hamiltonian cycle.
// O(n)

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<int> edges[n + 1];
		cin >> ws;
		string s;
		while (getline(cin, s) && s != "%") {
			stringstream ss(s);
			int a, b;
			ss >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		
		vector<int> ans, used(n + 1, false);
		function <void(int)> Dfs = [&] (int node) {
			used[node] = true;
			ans.push_back(node);
			for(int child : edges[node]) {
				if(!used[child]) {
					Dfs(child);
				}
			}
		};
		
		Dfs(1);
		if((int)ans.size() == n) {
			printf("%d", ans[0]);
			for(int i = 1; i < n; ++i) {
				printf(" %d", ans[i]);
			}
			printf(" %d\n", ans[0]);
						
		} else puts("N");
		
	}
	
	return 0;
}
