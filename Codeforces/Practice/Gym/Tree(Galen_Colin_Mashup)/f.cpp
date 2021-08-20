#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)2e5 + 10;
vector<int> edges[nax];
int tin[nax], tout[nax];
int up[nax][33], h[nax];

int l , timer = 0;
void Dfs(int node, int par, int ht ) {
	tin[node] = ++timer;
	h[node] = ht;
	up[node][0] = par;
	for(int i = 1; i <= l; ++i) {
		up[node][i] = up[up[node][i -1]][i -1];
	}

	for(int child : edges[node]) {
		if(child != par) {
			Dfs(child, node, ht + 1) ;
		}
	}
	tout[node] = ++timer;
}

bool Ancestor(int a, int b ) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int Lca(int a, int b) {
	if(Ancestor(a, b)) return a;
	if(Ancestor(b, a)) return b;

	for(int i = l; i >= 0; --i) {
		if(!Ancestor(up[a][i], b)) {
			a = up[a][i];
		}
	}
	return up[a][0];
}

	
	

int main() {
	int n, qq;
	scanf("%d %d", &n, &qq);
	l = ceil(log2(n));

	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	auto cmp = [] (const int & a, const int & b) {
		return h[a] < h[b];
	};
	
	Dfs(1, 1, 0);

	while( qq-- ) {
		int m;
		scanf("%d", &m);
		vector<int> v(m);
		for(int & x : v) {
			scanf("%d", &x);
		}

		sort(v.begin() , v.end(), cmp);
		bool ok = true;
		int curr = v[m - 1];
		for(int i = m - 2; i >= 0; --i) {
			int x = Lca(v[i], curr);
			if(x != v[i] && up[v[i]][0] != x) {
				ok = false;
				break;
			} else curr = x;
		}
		puts( ok ? "Yes" : "No");
	}
	return 0;
}	
