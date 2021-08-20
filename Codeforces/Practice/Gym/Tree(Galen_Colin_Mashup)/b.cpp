#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class Hello :
const int nax = (int)1e5 + 10;
vector<int> edges[nax];

double Dfs(int node, int par, int dist, double prob) {
	const int n = (int)edges[node].size() - (node != 1);
	if(n == 0) {
		return prob * dist;
	}
	double ans = 0;
	
	for(int child : edges[node]) {
		if(child != par) {
			ans += Dfs(child, node, dist + 1, prob/n);
		}
	}
			
	return ans;
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	double ans = Dfs(1, 0, 0, 1.0);
	printf("%.10f\n", ans);
	return 0;	
	
}
