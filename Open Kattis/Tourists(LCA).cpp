#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)2e5 + 10;
vector<int> edges[nax];
int tin[nax], tout[nax], d[nax];
int up[nax][63];
int n, l, timer;

void Dfs(int node, int par, int x){
	d[node] = x;
	tin[node] = ++timer;
	up[node][0] = par;
	for(int i = 1; i <= l; ++i){
		up[node][i] = up[up[node][i - 1]][i - 1];
	}	
	
	for(int child : edges[node]){
		if(child != par){
			Dfs(child, node, x + 1);
		}
	}
	
	tout[node] = ++timer;
}

bool Ancestor(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int Lca(int a, int b){
	if(Ancestor(a, b)) return a;
	if(Ancestor(b, a)) return b;
	
	for(int i = l ; i >= 0; --i){
		if(!Ancestor(up[a][i], b)){
			a = up[a][i];
		}
	}
	return up[a][0];
}

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i){
		int a, b ;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	l = ceil(log2(n));
	Dfs(1, 1, 0);

	long long answer = 0;
	
	for(int i = 1; i <= n; ++i){
		for(int j = 2 ; j * i <= n; ++j){
			int x = Lca(i, i * j);
			int dist =  d[i] + d[i * j] - 2 * d[x] + 1;
			answer += dist;
		}
	}
	
	printf("%lld\n", answer);
}
	

int main(){
	int tt;
	tt = 1;
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;	
}
