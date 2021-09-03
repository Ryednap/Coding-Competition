#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/**
 * The concept behind the problem is that no matter what type of graph is present
 * If the graph is fully connected then the size of the strongly-connected component 
 * if always the total vertices. (Note that undirected graph are always scc).
 * 
 */

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using vpi = vector<pii>;

#define f first
#define s second

vvi edges;
vi tin, low;
vi instck;
stack<int> st;

int timer = 0, cnt = 0;

void dfs (int node) {
	tin[node] = low[node] = ++timer;
	st.push(node);
	instck[node] = 1;
	for (int child : edges[node]) {
		if (tin[child] == -1) {
			dfs (child);
			low[node] = min (low[node], low[child]);
		} else if(instck[child]) {
			low[node] = min (low[node], tin[child]);
		}
	}

	if (low[node] == tin[node]) {
		while (true) {
			int v = st.top(); st.pop();
			++cnt;
			instck[v] = 0;
			if (v == node)
				break;
		}
		if (cnt != (int)edges.size()) cnt = 0;
	}
}

int main () {
	int n, m;
	while (scanf ("%d %d", &n, &m)) {
		if (!n && !m)
			break;
		edges = vvi(n);
		tin = low = vi(n, -1);
		instck = vi(n);
		timer = cnt = 0;

		for (int i = 0; i < m; ++i) {
			int u, v, w;
			scanf ("%d %d %d", &u, &v, &w);
			--u, --v;
			edges[u].push_back(v);
			if (w == 2) edges[v].push_back(u);
		}
		dfs (0);
		if (cnt != n) puts ("0");
		else puts ("1");
	}

}