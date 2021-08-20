#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif



using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;

#define f first
#define s second

int n;
vvi mat;
vi used;
void dfs (int v) {
	used[v] = true;
	for (int i = 0; i < n; ++i) {
		if (mat[v][i] && !used[i])
			dfs (i);
	}
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		scanf ("%d", &n);
		mat = vvi(n, vi(n));
		for (int i = 0; i < n; ++i) {
			for (int & x : mat[i])
				scanf ("%d", &x);
		}
		auto ans = vvi(n, vi(n));
		used = vi(n);
		dfs (0);
		auto before = used;
		for (int i = 0; i < n; ++i) {
			auto store = mat[i];
			used = mat[i] = vi(n, 0);
			dfs (0);
			mat[i] = store;
			for (int j = 0; j < n; ++j) {
				if (used[j])
					assert (before[j]);
				if (before[j] && !used[j])
					ans[i][j] = true;
			}
		}
		printf ("Case %d:\n", tt);
		for (int i = 0; i < n; ++i) {
			printf ("+");
			for ( int j = 0; j < 2 * n - 1; ++j) {
				printf("-");
			}
			puts("+");
			for (int j = 0; j < n; ++j) {
				if (i == j && before[j]) ans[i][j] = true;
				printf("|%c", ans[i][j] ? 'Y' : 'N');
			}
			puts("|");
		}
		printf ("+");
		for ( int j = 0; j < 2 * n - 1; ++j) {
			printf("-");
		}
		puts("+");
	}
	return 0;
}