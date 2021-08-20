#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


void solve(){
	long long x;
	scanf("%lld",&x);
	int cnt = __builtin_popcountll(x);
	printf("%lld\n",2LL * x - cnt);
		
}


int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0;i < tt; ++i){
		solve();
	}
	
	return 0;
}
