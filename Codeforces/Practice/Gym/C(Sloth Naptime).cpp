#include<bits/stdc++.h>
using namespace std;

const int nax = (int)3e5 + 10;
vector<int> edges[nax];
int tin[nax], tout[nax];
int up[nax][63], d[nax];
int n, l, timer;

void Dfs(int node, int par, int x) {
	d[node] = x;
	tin[node] = ++timer;
	up[node][0] = par;
	for(int i = 1; i <= l ; ++i) {
		up[node][i] = up[up[node][i - 1]][i -1];
	}
	
	for(int child : edges[node]) {
		if(child != par){
			Dfs(child , node ,x + 1);
		}
	}
	tout[node] = ++timer;
}

bool Ancestor(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int Lca(int a, int b) {
	if(Ancestor(a, b)) return a;
	if(Ancestor(b, a)) return b;
	for(int i = l; i >= 0; --i){
		if(!Ancestor(up[a][i], b)){
			a = up[a][i];
		}
	}
	return up[a][0];
}

int Walk(int a, int x){
	for(int i = 0; i < 36; ++i){
		if(x & (1LL << i)){
			a = up[a][i];
		}
	}
	return a;
}

int main(){
	scanf("%d",&n);	
	l = ceil(log2(n));
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		scanf("%d %d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	Dfs(1, 1, 0);
	
	int q;
	scanf("%d", &q);
	while(q--){
		int a, b, c;
		scanf("%d %d %d",&a, &b, &c);
		int x = Lca(a, b);
		int path1 = d[a] - d[x];
		int path2 = d[b] - d[x];
		if(c >= path1 + path2){
			printf("%d\n", b);
		} else if(c > path1){
			
			c -= path1 ; // Wrong here.
			c = path2 - c;
			printf("%d\n", Walk(b, c));
					
		} else {
			printf("%d\n", Walk(a, c));
		}
	}
	return 0;
}
