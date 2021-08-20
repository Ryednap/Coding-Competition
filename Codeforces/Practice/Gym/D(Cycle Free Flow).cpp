#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)3e5 + 3e4;
using pii = pair<int, int> ;
vector<pii> edges[nax];

int l;
int d[nax];
int up[nax][60], Min[nax][60];

#define f first
#define s second

void Dfs(int node, int par, int wt, int dep ) {
	d[node] = dep;
	up[node][0] = par;
	Min[node][0] = wt;
	for(int i = 1; i <= l ; ++i) {
		up[node][i] = up[up[node][i-1]][i-1];
		Min[node][i] = min(Min[node][i - 1], Min[up[node][i - 1]][i - 1]);
	}
	
	for(pii child : edges[node]) {
		if(child.f != par ) {
			Dfs(child.f, node, child.s , dep + 1);
		}
	}
}

int Walk(int a, int x, int & val) {
	if(x == 0){
		return a;
	}
	for(int i = 0; i <= l; ++i) {
		if(x & (1LL << i)) {
			val = min(val, Min[a][i]);
			a = up[a][i];
		}
	}
	return a;
}

int Find(int a, int b){
	int res = (int)2e9 + 10;
	if(d[a] > d[b]) a = Walk(a, d[a] - d[b], res);
	if(d[b] > d[a]) b = Walk(b, d[b] - d[a], res);
	
	assert(d[a] == d[b]);
	
	int lo = 0, hi = l;
	int pos = -1;
	while(lo <= hi) {
		int mid = (lo + hi)/2;
		int temp ;
		if(Walk(a, mid, temp) == Walk(b, mid, temp)) {
			hi = mid  - 1;
			pos = mid;
		} else lo = mid + 1;
	}
	
	a = Walk(a, pos, res);
	b = Walk(b, pos, res);
	assert(a == b);
	assert(res != 0);
	return res;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	l = ceil(log2(n));
	
	for(int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back( {b, c});
		edges[b].push_back( {a, c});
	}
	
	Dfs(1, 1, (int)2e9 + 100, 0);

	int qq;
	scanf("%d", &qq);
	while(qq --) {
		 int a, b;
		 scanf("%d%d", &a, &b);
		 printf("%d\n", Find(a, b));
	}
	return 0;
}
