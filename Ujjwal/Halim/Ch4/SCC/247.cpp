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
stack<int> st;
vi low, instck, tin;
int timer = 0;

vector<vector<int>> scc;

void dfs (int node) {
	tin[node] = low[node] = ++timer;;
	instck[node] = true;
	st.push(node);
	for (int child : edges[node]) {
		if (low[child] == -1) {
			dfs (child);
		}
		if (instck[child]) {
			low[node] = min (low[node], low[child]);
		}
	}
	if (low[node] == tin[node]) {
		vector<int> vec;
		while (true) {
			int v = st.top(); st.pop();
			instck[v] = false;
			vec.push_back(v);
			if (node == v)
				break;
		}
		scc.push_back(vec);
	}
}

int main () {
	int n, m;
	int tt = 0;
	scanf ("%d %d", &n, &m);
	while (true) {
		if (!n && !m)
			break;
		// clear
		edges = vvi(n + 1);
		tin = low = instck = vi(n, -1);
		st = stack<int>();
		scc.clear();
		timer = 0;
		// dec
		unordered_map<string, int> mapper;
		unordered_map<int, string> flapper;
		for (int i = 0, j = 0; i < m; ++i) {
			string a, b;
			cin >> a >> b;
			if (mapper.find(a) == mapper.end()) 
				mapper[a] = j++;
			if (mapper.find(b) == mapper.end()) 
				mapper[b] = j++;

			int u = mapper[a];
			int v = mapper[b];
			flapper[u] = a;
			flapper[v] = b;
			edges[u].push_back(v);
		}
		for (int i = 0; i < n; ++i) {
			if (tin[i] == -1)
				dfs (i);
		}
		printf ("Calling circles for data set %d:\n", ++tt);
		for (auto v : scc) {
			if (m == 0)
				break;
			if ((int)v.size() == 0)
				continue;
			printf ("%s", flapper[v[0]].c_str());
			for (int i = 1; i < (int)v.size(); ++i) {
				printf (", %s", flapper[v[i]].c_str());
			}
			puts ("");
		}
		scanf ("%d %d", &n, &m);
		if (!n && !m)
			break;
		puts("");
	}
	return 0;
}