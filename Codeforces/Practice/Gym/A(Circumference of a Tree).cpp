#include<bits/stdc++.h>
using namespace std;

const int nax = (int)3e5 + 10;
vector<int> edges[nax];

int dist[nax];
void dfs(int node,int par, int x){
	dist[node] = x;
	
	for(int child : edges[node]){
		if(child != par){
			dfs(child, node, x + 1);
		}
	}
}

int Diameter(){
	dfs(1, 0, 0);
	int x = 0, maxi = 0;
	for(int i = 0; i < nax; ++i){
		if(dist[i] > maxi){
			x = i;
			maxi = dist[i];
		}
	}
	memset(dist,0, sizeof(dist));
	dfs(x, 0, 0);
	maxi = 0;
	for(int i = 0; i < nax; ++i){
		maxi = max(maxi, dist[i]);
	}
	return maxi;
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
	
	int d = Diameter();
	printf("%d", 3 * d);
	return 0;
}
