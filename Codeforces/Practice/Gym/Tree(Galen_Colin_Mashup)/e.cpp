#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)2e5 + 10;
vector<int> edges[nax];
long long s[nax], a[nax], total = 0;
long long ans[nax];

long long dfs0(int node,int par, int ht) {
		total += ht * a[node];
		long long res = 0;
		for(int child : edges[node]) {
			if(child != par) {
				res += dfs0(child, node, ht + 1);
			}
		}
		return s[node] = res + a[node];
}

void dfs1(int node, int par) {
	ans[node] = ans[par] + s[1] - 2 * s[node];
	for(int child : edges[node]) {
		if(child != par)
			dfs1(child, node);
	}
}
	

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs0(1,0,0);
	ans[1] = total;
	for(int child : edges[1]) {
		dfs1(child, 1);
	}
	long long answer = 0;
	for(int i = 0; i <= n; ++i) {
		answer = max(answer, ans[i]);
	}
	printf("%lld\n", answer);
	return 0;
}
