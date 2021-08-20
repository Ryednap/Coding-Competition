#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif



using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using piii = std::pair<int, pii>;
using vpi = std::vector<pii>;

#define f first
#define s second

vvi edges;
vi used;

int dfs (int node) {
	used[node] = true;
	int cnt = 1;
	for (int child : edges[node]) {
		if (!used[child])
			cnt += dfs(child);
	}
	return cnt;
}

int main () {
	int n, m;
	while (cin >> n >> m) {
		if (!n && !m)
			break;
		edges = vvi(n);
		used = vi(n);
		vector<piii> v ;
		int maxi_cost = -INT_MAX;
		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			v.emplace_back(c, pii(a, b));
			maxi_cost = std::max(maxi_cost, c);
		}

		for (auto p : v) {
			if (p.f != maxi_cost)
				continue;
			edges[p.s.f].push_back(p.s.s);
			edges[p.s.s].push_back(p.s.f);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				ans = std::max(ans, dfs(i));
			}
		}
		assert (ans >= 2);
		printf ("%d\n", ans);
	}
}