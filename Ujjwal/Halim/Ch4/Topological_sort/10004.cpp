#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;

vvi edges;
vi color;

bool dfs (int node) {
	array<int, 2> avail = {true, true};
	for (int child : edges[node]) {
		if (color[child] != -1)
			avail[color[child]] = false;
	}

	for (int i = 0; i < 2; ++i) {
		if (avail[i]) {
			color[node] = i;
			bool ok = true;
			for (int child : edges[node]) {
				if (color[child] == -1)
					ok &= dfs (child);
			}
			return ok;
		}
	}
	return false;
}

int main () {
	int n;
	while (scanf ("%d", &n) && n) {
		int m;
		scanf ("%d", &m);
		edges = vvi(n);
		color = vi(n, -1);
		for (int i = 0; i < m; ++i) {
			int a, b ;
			scanf ("%d %d", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		bool ans = dfs(0);
		puts (!ans ? "NOT BICOLORABLE." : "BICOLORABLE.");
	}
}