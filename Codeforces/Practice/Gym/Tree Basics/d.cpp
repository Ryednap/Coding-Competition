#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int maybe = -1;
const int nax = (int)2e5 + 10;
vector<int> edges[nax];
int c[nax];

bool Dfs1(int node, int par, const int root) {
	bool ok = true;
	for(int child : edges[node]) {
		if(child != par) {
			if(node != root && c[node] != c[child]) {
				return false;
			} else ok &= Dfs1(child, node, root);
		}
	}
	return ok;
}

bool Dfs0(int node, int par) {
	bool ok = true;
	for(int child : edges[node] ) {
		if(child != par) {
			if(c[child] != c[node]) {
				if(Dfs1(node, 0, node)) {
					maybe = node;
					return true;
				} else if(Dfs1(child, 0, child)) {
					maybe = child;
					return true;
				} else return false;
				
			} else ok &= Dfs0(child, node);
		}
	}
	return ok;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d",&a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&c[i]);
	}
	
	bool ok = Dfs0(1, 0);
	puts(ok ? "YES" : "NO");
	if(ok) {
		printf("%d\n", maybe == -1 ? 1 : maybe);
	}
	return 0;
}
