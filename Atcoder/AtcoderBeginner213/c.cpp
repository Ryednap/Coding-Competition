#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define mp(a, x) make_pair(a, x);
#define sz(x) ((int)x.size())



int main () {
	int q, u;
	scanf ("%d %d", &q, &u);
	int n;
	scanf ("%d", &n);
	vector<array<int, 2>> ans(n);
	vector<pii> row(n), col(n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d %d", &row[i].f, &col[i].f);
		row[i].s = col[i].s = i;
	}

	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	map<int, int> a, b;
	
	for (int i = 0, j = 0; i < n; ++i) {
		if(a.find(row[i].f) == a.end())
			a[row[i].f] = ++j;
		ans[row[i].s][0] = a[row[i].f];
	}
	for (int i = 0,j = 0; i < n; ++i) {
		if(b.find(col[i].f) == b.end())
			b[col[i].f] = ++j;
		ans[col[i].s][1] = b[col[i].f];
	}
	for (int i = 0; i < n; ++i) {
		printf ("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}