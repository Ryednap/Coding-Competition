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
int timer = 0, root = 0;
set<int> art;

void dfs (int node, int par) {
	tin[node] = low[node] = ++timer;
	for (int child : edges[node]) {
		if (tin[child] == -1) {
			dfs (child, node);
			low[node] = std :: min (low[node], low[child]);
			if (tin[node] <= low[child]) {
				if (tin[node] == 1 && !root)
					root = true;
				else 
					art.insert (node);
			}
		} else if (child != par) {
			low[node] = std :: min (tin[child], low[node]);
		}
	}
}


int main () {
	int n;
	while (scanf("%d", &n) && n) {
		edges = vvi(n);
		low  = tin = vi(n , -1);
		std :: string s;
		cin >> ws;
		while (getline(cin, s)) {
			stringstream ss(s);
			int u, v;
			ss >> u;
			if (u == 0)
				break;
			while (ss >> v) {
				edges[u - 1].push_back(v - 1);
				edges[v - 1].push_back(u - 1);
			}
		}
		timer = root = 0;
		art.clear();
		dfs (0, -1);
		int ans = (int)art.size();
		printf ("%d\n", ans);
	}
	return 0;
}