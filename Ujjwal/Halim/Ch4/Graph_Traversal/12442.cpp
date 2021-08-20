#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
T 000:50:31.328

T 000:42:33.232
T 000:12:12.385
T 000:04:48.251
T 000:01:54.637

*/

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;

#define f first
#define s second

vvi edges;
vi par, cnt, used;

void dfs (int node, int i) {
	par[node] = i;
	used[node] = true;
	cnt[i]++;
	for (int child : edges[node]) {
		if (par[child] == -1) {
			dfs (child, i);
		} else  {
			cnt[i] += cnt[par[child]];
		}
	}
}
int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 0; tt < qq; ++tt) {
		printf ("Case %d: ", tt + 1);
		int n;
		scanf ("%d", &n);
		edges = vvi (n);
		par = vi(n, -1);
		cnt = vi(n, 0);
		used = vi(n, false);

		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf ("%d %d", &a, &b);
			--a, --b;
			edges[a].push_back(b);
		}
		
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				dfs (i, i);
			}
		}
		printf ("%d\n", max_element(cnt.begin(), cnt.end()) - cnt.begin() + 1);
	}
	return 0;
}