#include<bits/stdc++.h>
using namespace std;

const int nax = (int)3e5 + 10;
vector<int> edges[nax];

int dist[nax];
void Dfs(int node,int par, int x){
	dist[node] = x;
	
	for(int child : edges[node]){
		if(child != par){
			Dfs(child, node, x + 1);
		}
	}
}

auto Diameter(int n){
	Dfs(1, 0, 0);
	map<int, bool > mp;
	int m = 0, x = 0;
	for(int i = 1;i <= n; ++i) m = max(m, dist[i]);
	for(int i = 1; i <= n; ++i){
		if(dist[i] == m){
			mp[i] = true;
			x = i;
		}
	}
	
	memset(dist, 0, sizeof(dist));
	Dfs(x, 0, 0);
	m = 0;
	for(int i = 1; i <= n; ++i) m = max(m , dist[i]);
	for(int i = 1; i <= n; ++i) {
		if(dist[i] ==m){
			mp[i] = true;
		}
	}
	
	vector<int> ans;
	for(int i = 1; i <= n; ++i){
		if(mp[i]) ans.push_back(m + 1);
		else ans.push_back(m);
	}
	return ans;
	
}
	 
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n - 1; ++i){
		int a, b;
		scanf("%d %d",&a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	vector<int> ans = Diameter(n);
	for(int x : ans){
		printf("%d\n", x);
	}
	return 0;
}
