#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 000:09:33.753
T 000:02:37.038

*/

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;

#define f first
#define s second

vvi edges;
vi cost;
int fin = -1;

int dfs (int node) {
	if (edges[node].empty()) {
		fin = node;
		return cost[node];
	}
	int maxi = 0, where = -1;
	for (int child : edges[node]) {
		if(cost[child] > maxi) {
			maxi = cost[child];
			where = child;
		}
	}
	return cost[node] + dfs (where);
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 0; tt < qq; ++tt) {
		printf ("Case %d: ", tt + 1);
		int n, m;
		scanf ("%d %d", &n, &m);
		cost = vi(n);
		edges = vvi(n);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &cost[i]);
		}
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf ("%d %d", &a, &b);
			edges[a].push_back(b);
		}
		int val = dfs(0);
		printf ("%d %d\n", val, fin);
	}
}
