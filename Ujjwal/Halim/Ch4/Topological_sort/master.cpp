#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;

vvi edges;
vi link, color;
vi connection(1000);
int timer = 0;

void dfs (int node, int par, int c) {
	link[node] = timer++;
	color[node] = connection[c];
	for (int child : edges[node]) {	
		if (link[child] == -1) {
			dfs (child, node, color[node]);
			link[node] = min (link[node], link[child]);
		} else if (child != par) {
			link[node] = min (link[node], link[child]);
		}
	}
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int i = 0; i < 1000; i += 2) {
		connection[i] = i + 1;
		connection[i + 1] = i;
	}
	for (int tt = 0; tt < qq; ++tt) {
		int n;
		scanf ("%d", &n);
		edges = vvi(210);
		link = color = vi(210, -1);
		timer = 0;

		for (int i = 0; i < n; ++i) {
			int m;
			scanf ("%d", &m);
			for (int _ = 0; _ < m; ++_) {
				int a; scanf ("%d", &a);
				--a;
				assert (a < 210);
				assert (i < 210);
				edges[a].push_back(i);
				edges[i].push_back(a);
			}
		}
		for (int i = 0, j = 0; i < 201; ++i) {
			if (color[i] == -1) {
				dfs (i, -1, connection[j]);
				j += 2;
			}
		}

		vi count(n, 0);
		for (int i = 0; i < 201; ++i) {
			count[link[i]]++;
		}


		vi ans(110, 0);
		for (int i = 0; i < 201; ++i) {
			if (count[link[i]] == 1) {
			 	ans[color[i]]++;
			}
		}
		int res = 0;
		for (int i = 0; i < 110; i += 2) {
			res += max(ans[i], ans[i + 1]);
		}
		printf ("%d\n", res);
	}
	return 0;
}