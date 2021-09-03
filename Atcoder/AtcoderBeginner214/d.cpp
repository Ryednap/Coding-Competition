#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using vpi = std::vector<pii>;
using vvpi = std::vector<vpi>;


#define f first
#define s second

const int nax = 1e5 + 10;
int par[nax], siz[nax];

int get (int i) {
	if (par[i] == i) return i;
	return par[i] = get(par[i]);
}

void unite (int a, int b){
	a = get(a);
	b = get(b);
	if (a != b) {
		if (siz[a] > siz[b]) swap(a, b);
		par[b] = a;
		siz[a] += siz[b];
	}
}


int main () {
	int n;
	scanf ("%d", &n);
	vector<pair<int, pii>> edges(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d %d", &edges[i].s.f, &edges[i].s.s, &edges[i].f);
	}
	sort (edges.begin(), edges.end());
	for (int i = 0; i < nax; ++i) {
		par[i] = i;
		siz[i] = 1;
	}

	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		int w = edges[i].f;
		auto [u, v] = edges[i].s;
		int a = get(u), b = get(v);
		ans += 1ll * w * siz[a] * siz[b];
		unite(u, v);
	}
	printf ("%lld\n", ans);
}