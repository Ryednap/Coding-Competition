#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * What matters is the current difference in price now and then and the amount of k left.
 */

void solve(){
	int n, k;
	scanf("%d %d",&n,&k);

	int a[n], b[n];
	pair<int, int> c[n];
	for(int i = 0; i < n; ++i){
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d",&b[i]);
		c[i] = {b[i] - a[i], i};
	}
	sort(c, c + n, greater<pair<int, int> >());
	
	long long answer = 0;
	for(int i = 0; i < n; ++i){
		auto [cost, j] = c[i];
		if(cost >= 0 || k > 0){
			answer += a[j];
			--k;
		} else {
			answer += b[j];
		}
	}
	
	printf("%lld",answer);
}
	
	
	

int main(){
	int tt;
	//scanf("%d",&tt);
	tt = 1;
	for(int _ = 1;_ <=tt;++_ ){
		solve();
	}
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}
