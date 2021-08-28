#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/**
 * Recommeded problem
 * The problem statement of simple path is a bit confusing
 * From what I understood by the samples they are asking to print Y if there's just single path from a to b
 * So indirectly they are saying that the path between a and b must be connected by bridges or articulation points
 * 
 * Hint : We can use Trajan + dsu. 
 * O(V + E) complexity
 * 
 * 
 */

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpi = vector<pii>;
using vvpi = vector<vpi>;

#define f first
#define s second

vvi edges;
vi low, tin;
vpi bridges;
int timer = 0;

void dfs (int node, int par) {
	tin[node] = low[node] = ++timer;
	for (int child : edges[node]) {
		if (tin[child] == -1) {
			dfs (child, node);
			low[node] = min (low[node], low[child]);
			if (low[child] > tin[node]) {
				bridges.emplace_back(node, child);
			}
		} else if (child != par) {
			low[node] = min (low[node], tin[child]);
		}
	}
}

vi parent, siz;
int get (int a) {
	if (a == parent[a])
		return a;
	return parent[a] = get(parent[a]);
}

void unite (int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b) {
		if (siz[a] > siz[b]) 
			swap(a, b);
		parent[b] = a;
		siz[a] += siz[a];
	}
}

int main () {
	int n, m, q;
	while (scanf ("%d %d %d", &n, &m, &q)) {
		if (!n && !m && !q)
			break;
		edges = vvi(n);
		low = tin = vi(n, -1);
		timer = 0;
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf ("%d %d", &a, &b);
			--a, --b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		for (int i = 0; i < n; ++i) {
			if (tin[i] == -1)
				dfs (i, -1);
		}

		parent.resize(n);
		siz.resize(n);
		for(int i = 0; i < n; ++i) {
			parent[i] = i;
			siz[i] = 1;
		}

		for (pii & p : bridges) {
			unite(p.f, p.s);
		}
		while (q--) {
			int a, b;
			scanf ("%d %d", &a, &b);
			if (get(a - 1) == get(b -1))
				puts("Y");
			else puts("N");
		}
		puts ("-");
		bridges.clear();
	}
}