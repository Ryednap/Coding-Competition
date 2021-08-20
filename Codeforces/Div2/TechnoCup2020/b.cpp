#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

bool Valid(long long x){
	long long a = x;
	while(a){
		int digit = a % 10;
		a /= 10;
		if(digit == 0) continue;
		if(x % digit != 0) return false;
	}
	return true;
}

void Solve(){
	long long n;
	scanf("%lld",&n);
	
	while(!Valid(n)) ++n;
	printf("%lld\n", n);
	
}

int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		Solve();
	}
	return 0;
}
