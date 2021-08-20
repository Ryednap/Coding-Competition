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
vi ans;

void dfs (int node, int par) {
	tin[node] = low[node] = ++timer;
	int cnt = 0;
	for (int child : edges[node]) {
		if (tin[child] == -1) {
			dfs (child, node);
			low[node] = std :: min (low[node], low[child]);
			if (tin[node] <= low[child]) {
				if (tin[node] == 1 && !root) // reject first bcc / art for root node
					root = true;
				else {
					art.insert (node);
					++cnt;
				}
			}
		} else if (child != par) {
			low[node] = std :: min (tin[child], low[node]);
		}
	}
	if (art.find(node) != art.end()){
		ans[node] = cnt + 1;
	}
}


int main () {
	int n, m;
	while (scanf ("%d %d", &n, &m)) {
		if (!n && !m)
			break;
		edges = vvi(n);
		low = tin = vi(n, -1);
		ans = vi(n, 0);
		int u, v;
		while (scanf ("%d %d", &u, &v)) {
			if (u == -1 && v == -1)
				break;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		timer = root = false;
		art.clear();

		dfs (0, -1);

		vector<pii> res;
		for (auto x : art) {
			res.emplace_back(ans[x], x);
		}
		for (int i = 0; i < n; ++i) {
			if (art.find(i) == art.end())
				res.emplace_back(1, i);
		}
		sort (res.begin(), res.end(), [&] (const pii & a, const pii & b){
			if (a.f == b.f)
				return a.s < b.s;
			return a.f > b.f;
		});
		assert ((int)res.size() >= m);
		for (int i = 0; i < m; ++i) {
			printf ("%d %d\n", res[i].s, res[i].f);
		}
		puts("");
	}
	return 0;
}

/*

TESTING INPUT

8 4
0 4
1 2
2 3
2 4
3 5
3 6
3 7
6 7
-1 -1

3 3
0 1
1 2
2 0
-1 -1

5 4
0 1
1 2
2 0
0 3
3 4
4 0
-1 -1

7 2
0 1
1 2
2 0
0 3
3 4
4 5
5 6
6 4
-1 -1

4 4
0 1
1 2
2 3
-1 -1
0 0

*/

/*

TESTING OUTPUT


2 3
3 3
4 2
0 1

0 1
1 1
2 1

0 2
1 1
2 1
3 1

0 2
3 2

1 2
2 2
0 1
3 1

*/