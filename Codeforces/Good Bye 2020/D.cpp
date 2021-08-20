#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


void solve(){
	int n;
	scanf("%d", &n);
	
	long long total = 0;
	int w[n];
	for(int i = 0; i < n; ++i){
		scanf("%d", &w[i]);
		total += w[i];
	}
	
	
	int deg[n] = {0};
	for(int i = 0; i < n - 1; ++i){
		int a, b;
		scanf("%d %d",&a,&b);
		--a, --b;
		deg[a]++;
		deg[b]++;
	}
	
	vector<int> val;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < deg[i] - 1; ++j) val.push_back(w[i]);
	}
	sort(val.begin(), val.end(), greater<int>());
	
	printf("%lld ", total);
	for(int x : val){
		printf("%lld ", total += x);
	}
	puts("");
}

int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;
}
