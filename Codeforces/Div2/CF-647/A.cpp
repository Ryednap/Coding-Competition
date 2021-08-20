#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


void solve(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	if(a > b) swap(a, b);
	
	if(b % a != 0) puts("-1");
	else {
		long long x = b/ a;
		if( !(x & (x - 1))){
			int z = log2(x);
			printf("%d\n", z/3 + (z%3)/2  + (z%3)%2);
		
		} else puts("-1");
	}
}


int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0;i < tt; ++i){
		solve();
	}
	
	return 0;
}
