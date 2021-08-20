#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Quite easy as usual.Much similar to binary searching. we can also do that via lo and mid but by observation i came to this method.
 * 
 */

void solve(){
	int n;
	long long k;
	scanf("%d%lld",&n,&k);
	
	while(n){
		long long len = (1LL << n) - 1;
		long long mid = (len + 1) >> 1LL;
		if(mid == k){
			printf("%d\n",n);
			return;
		} else if(k > mid){
			k -= mid;
		}
		--n;
	}
	assert(false);
	
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
