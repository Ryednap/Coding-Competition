#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 *  Note that the pattern is that 1, 2, 4, 8,.. means this is the largest cover square that must be in fair staircase. Now in each one of them the height
 *  should be of length 2^k - 1.
 */

long long F(long long x){
	x = x - 1;
	return (x * (x + 1)) >> 1;
}
void solve(){
	long long x;
	scanf("%lld",&x);
	
	int cnt = 0;
	long long tot = 0;
	for(int k = 0; ; ++k){
		tot += (F(1LL << k));
		if(tot > x) break;
		cnt = k;
	}
	
	printf("%d\n", cnt);
}
	
int main(){
	int tt;
	scanf("%d",&tt);
	//tt = 1;
	for(int _ = 1;_ <=tt;++_ ){
		solve();
	}
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}
