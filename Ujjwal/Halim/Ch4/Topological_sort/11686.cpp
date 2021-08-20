#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;

vvi edges;
vi color, ans;
bool possible;

void dfs ( int node, int par ) {
	color[node] = 1;
	for (int child : edges[node]) {
		if (color[child] == 0) {
			dfs (child, node);

		} else if (color[child] == 1 && child != par) {
			possible = false;
			return;
		}
	}
	color[node] = 2;
	ans.push_back(node);
}

int main () {
	int n, m;
	while (scanf ("%d %d",&n, &m)) {
		if (!n && !m)
			break;
		edges = vvi(n);
		color = vi(n);
		ans = vi();
		possible = true;

		for (int i = 0; i < m; ++i) {
			int a, b; 
			scanf ("%d %d", &a, &b);
			--a, --b;
			edges[a].push_back(b);
		}
		for (int i = 0; i < n; ++i) {
			if (!color[i]) 
				dfs(i, -1);
		}
		reverse (ans.begin(), ans.end());
		if (possible) {
			for (int & x : ans) {
				printf ("%d\n", x + 1);
			}
		} else puts("IMPOSSIBLE");
	}
	return 0;
}