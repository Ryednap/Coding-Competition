#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)1e5 + 10;
vector<int> edges[nax];
int val[nax];
vector<int> ans;

void Dfs(int node,int par) {
	
	bool ok = true;
	if(!val[node]) ok = false;
	else {
		for(int child : edges[node]) {
			if(child != par) {
				if(!val[child]) ok = false;
			}
		}
	}
	
	if(ok) ans.push_back(node);
	for(int child : edges[node]) {
		if(child != par) {
			Dfs(child, node);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int root = 0 ;
	for(int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d %d",&a, &b);
		val[i] = b;
		if(a == -1) {
			root = i;
		} else {
			edges[a].push_back(i);
			edges[i].push_back(a);
		}
	}
	assert(val[root] == 0);
	Dfs(root, 0);
	sort(ans.begin(), ans.end());
	if((int)ans.size() == 0){
		puts("-1");
	} else {
		for(int x : ans) {
			printf("%d ", x);
		}
	}
	return 0;
}
