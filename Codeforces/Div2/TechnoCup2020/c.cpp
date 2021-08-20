#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

vector<int> parent;
int Get(int a){
	return parent[a] == a ? a : parent[a] = Get(parent[a]);
}

bool Unite(int a, int b){
	a = Get(a);
	b = Get(b);
	if(a != b){
		parent[a] = b;
		return false;
	} 
	return true;
}

void Solve(){
	int n, m;
	scanf("%d %d",&n,&m);
	parent.resize(n + 1);
	for(int i = 1; i <= n; ++i){
		parent[i] = i;
	}
	
	int ans = m;
	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a, &b );
		if(a == b) --ans;
		else if(Unite(a, b)) ++ans;
	}
	printf("%d\n", ans);
}

int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		Solve();
	}
	return 0;
}
