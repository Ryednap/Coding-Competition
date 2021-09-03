#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpi = vector<pii>;
using vvpi = vector<vpi>;

#define f first
#define s second

vvi edges;
vi low, tin;
int timer = 0;
vector<pii> bridges;

void dfs (int node, int par) {
	tin[node] = low[node] = ++timer;
	for (int child : edges[node]) {
		if (tin[child] == -1) {
			dfs (child, node);
			low[node] = min (low[node], low[child]);
			if (low[child] > tin[node]) {
				bridges.emplace_back(node,child);
			}
		} else if(child != par) {
			low[node] = min (low[node], tin[child]);
		}
	}
}

int main () {
	int n, m;
	while (scanf ("%d %d", &n, &m)) {
		if (!n && !m)
			break;
		edges = vvi(n);
		low = tin = vi(n, -1);
		timer = 0;
		bridges = vector<pii>();
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf ("%d %d", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		dfs (0, -1);
		for (auto & p : bridges) {
			if (p.f > p.s)
				swap(p.f, p.s);
		}
		sort(bridges.begin(), bridges.end(), [&](const pii & a, const pii & b) {
			if(a.f == b.f)
				return a.s < b.s;
			return a.f < b.f;
		});
		printf ("%d", (int)bridges.size());
		if (!bridges.empty()) {
			printf ("% d %d", bridges[0].f, bridges[0].s);
			for (int i = 1; i < (int)bridges.size(); ++i) {
				printf(" %d %d", bridges[i].f, bridges[i].s);
			}
		}
		puts("");
	}
	return 0;
}