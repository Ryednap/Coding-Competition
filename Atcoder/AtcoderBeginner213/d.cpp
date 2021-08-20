#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define mp(a, x) make_pair(a, x);
#define sz(x) ((int)x.size())

vvi edges;
vi ans, used;

void dfs (int node) {
	used[node] = true;
	ans.push_back(node);
	set<int> ne(edges[node].begin(), edges[node].end());
	for (int child : ne) {
		if (!used[child]) {
			dfs (child);
			ans.push_back(node);
		}
	}
}	

int main () {
	int n;
	scanf ("%d", &n);
	edges = vvi(n);
	used = vi(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf ("%d %d",&a, &b);
		--a,--b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs (0);
	for (auto x : ans) {
		printf ("%d ", x + 1);
	}
	return 0;
}