#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


const int nax = (int)3e5 + 10;
vector<int> edges[nax];
int s[nax], p[nax];
int n;

int Dfs0(int node, int par) {
	p[node] = par;
	int sz = 0;
	for(int child : edges[node]) {
		if(child != par) {
			sz += Dfs0(child, node);
		}
	}
	s[node] = sz;
	return sz + 1;
}

int Dfs1(int node, int par, const int sz) {
	int maybe = -1, maxi = 0;
	for(int child : edges[node]) {
		if(child != par) {
			if(s[child] > sz / 2 && maxi < s[child]) {
				maybe = child;
				maxi = s[child];
			}
		}
	}
	
	if(maybe == -1) return node;
	else return Dfs1(maybe, node, sz);
}
				

int main(){
	int qq;
	scanf("%d %d", &n, &qq);
	for(int i = 2; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		edges[x].push_back(i);
		edges[i].push_back(x);
	}
	Dfs0(1, 0);
	
	while( qq-- ) {
		int a;
		scanf("%d", &a);
		int ans = Dfs1(a,p[a], s[a]);
		printf("%d\n", ans);

	return0;
}
