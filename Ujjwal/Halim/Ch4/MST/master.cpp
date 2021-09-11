#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
using piii = pair<int, pii>;

int main () {
	int n, m, q, tt = 0;
	scanf ("%d %d %d", &n, &m, &q);
	while (true) {
		if (!n && !m && !q) break;
		printf ("Case #%d\n", ++tt);
		vector<piii> edges(m);
		for (auto & p : edges) {
			scanf ("%d %d %d", &p.second.first, &p.second.second, &p.first);
		}
		sort (edges.begin(), edges.end());

		vector<int> par(n + 1), rank(n + 1, 1);
		iota (par.begin(), par.end(), 0);

		function < int (int) > get = [&] (int ii) {return (ii == par[ii]) ? ii : (par[ii] = get(par[ii]));};
		auto merge = [&] ( int a , int b) -> bool {
			a = get(a), b = get(b);
			if (a != b) {
				if (rank[a] > rank[b]) swap(a, b);
				par[b] = a;
				rank[a] += rank[b];
				return true;
			}
			return false;
		};

		vector<vector<pii>> tree(n + 1);
		for (auto & p : edges) {
			if (merge(p.second.first, p.second.second)) {
				tree[p.second.first].emplace_back(p.second.second, p.first);
				tree[p.second.second].emplace_back(p.second.first, p.first);
			}
		}

		vector<vector<int>> mat(n + 1, vector<int> (n + 1, -1));
		int target = -1;
		function < void (int, int, int) > dfs = [&] (int u, int p, int maxi) {
			mat[target][u] = maxi;
			for (auto v : tree[u]) {
				if (v.first != p) dfs (v.first, u, std :: max (maxi, v.second));
			}
		};

		for (int i = 1; i <= n; ++i) {
			target = i;
			dfs (i, -1, 0);
		}
		while (q--) {
			int a, b;
			scanf ("%d %d", &a, &b);
			if (mat[a][b] == -1) puts("no path");
			else printf ("%d\n", mat[a][b]);
		}
		scanf ("%d %d %d", &n, &m, &q);
		if (!n && !m && !q) break;
		puts("");
	}
	return 0;
}