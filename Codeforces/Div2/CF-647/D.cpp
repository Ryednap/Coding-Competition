#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int,int>;
#define F first
#define S second

const int nax = (int)1e6;
vector<int> edges[nax];
vector<pii> add(nax);

bool used[nax];
bool dfs(int node){
	used[node] = true;
	
	map<int,bool> done;

	for(int child : edges[node]){
		{
			if(add[node].F == add[child].F) return false;
			if(add[node].F > add[child].F && add[node].S > add[child].S) done[add[child].F] = true;
		}
	}
	

	if((int)done.size() < add[node].F - 1) return false;
	done.clear();
	
	bool ok = true;
	for(int child : edges[node]){
		if(!used[child]){
			ok &= dfs(child);
		}
	}
	
	return ok;
}


void solve(){

	int n, m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d%d",&a,&b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	pii arr[n + 1];
	for(int i = 1; i <= n; ++i){
		scanf("%d",&arr[i].F);
		arr[i].S = i;
	}
	
	sort(arr + 1, arr + n + 1);
	for(int i = 1 ;i <= n; ++i){
		add [ arr[i].S ] = make_pair(arr[i].F, i);
	}
	
	bool ok = true;
	for(int i = 1; i <= n; ++i){
		ok &= dfs(i);
	}
	
	if(!ok) puts("-1");
	else {
		for(int i = 1; i <= n; ++i){
			printf("%d ", arr[i].S);
		}
		puts("");
	}
}


int main(){
	int tt;
	//scanf("%d",&tt);
	tt = 1;
	for(int i = 0;i < tt; ++i){
		solve();
	}
	
	return 0;
}
