#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)2e5 + 10;
vector<int> edges[nax];
vector<int> imp[nax];
long long val[nax], up[nax], down[nax];
int p[nax];

void dfs0(int node,int par) {
	p[node] =par;
	for(int child : edges[node]) {
		if(child != par) {
			dfs0(child, node);
		}
	}
}

int dfs1(int node, int par) {
	long long y = 0;
	for(int child : edges[node]) {
		if(child != par) {
			y += dfs1(child, node, x);
		}
	}
	
	
}
	
int main(){
	int n;
	scanf("%d",&n);
	
	vector<pii> v[n + 1];
	for(int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[i] ={a, b};
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs0(1, 0);
	int qq;
	scanf("%d" ,&qq);
	while(qq--) {
		int t, i, x;
		scanf("%d %d %d", &t, &i , &x);
		auto [a, b] = v[i];
		if(t = 2) swap(a, b);
		if(p[a] == b) {
			up[b] += x;
		} else down[b] += x;
	}
	dfs1(1, 0);
	for(int i = 1; i <= n; ++i) {
		printf("%d\n", val[i]);
	}
	return 0;
	
}
