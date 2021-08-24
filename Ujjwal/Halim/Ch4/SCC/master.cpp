#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using vpi = vector<pii>;

#define f first
#define s second


vvi edges;
vi tin, low, instck;
stack<int> st;
int timer = 0;
vi sc, indeg;

void dfs (int node) {
	tin[node] = low[node] = ++timer;
	instck[node] = true; st.push(node);
	for (int child : edges[node]) {
		if (tin[child] == -1) 
			dfs (child);
		if (instck[child])
			low[node] = min (low[node], low[child]);
	}
	if (low[node] == tin[node]) {
		int who = -1;
		while (true) { 
			int v = st.top(); st.pop();
			if (who == -1 || indeg[who] > indeg[v]){
				who = v;
			}
			instck[v] = false;
			if (v == node)
				break;
		}
		sc.push_back(who);
	}
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		printf ("Case %d: ", tt);
		int n, m;
		scanf ("%d %d", &n, &m);
	//  init 
		edges = vvi(n);
		tin = low = vi(n, -1);
		instck = indeg = vi(n);
		sc.clear();
		timer = 0;
	// end
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf ("%d %d", &a, &b);
			--a, --b;
			edges[a].push_back(b);
			indeg[b]++;
		}
		for (int i = 0; i < n; ++i) {
			if (tin[i] == -1) {
				dfs (i);
			}
		}
		sort (sc.begin(), sc.end(), [&] (const int & a, const int & b){
			return indeg[a] < indeg[b];
		});

		if (tt == 65) {
			debug() << owo(edges) owo(sc);
		}
		int ans = 0;
		vi vis(n);
		function < void(int) > dfs2 = [&] (int node) -> void {
			vis[node] = true;
			for (int child : edges[node]) {
				if (!vis[child])
					dfs2 (child);
			}
		};
		for (int & x : sc) {
			if (!vis[x]) {
				dfs2(x);
				++ans;
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}