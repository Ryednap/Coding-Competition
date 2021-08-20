#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// A pattern based problem.

const int nax = 999996;

bool isValid(int val, const int & x){
	int done[10];
	memset(done, false, sizeof(done));
	
	int sum = 0;
	while(val){
		int digit = val%10;
		sum += digit;
		if(done[digit]) return false;
		done[digit] = true;
		val /= 10;
	}
	
	return sum == x;
}

void solve(){
	int x;
	scanf("%d",&x);
	
	if(x > 45){
		puts("-1");
		return;
	}
	
	if(x >= 40){
		int ans = -1;
		switch(x){
			case 40 : ans = 1456789; break;
			case 41 : ans = 2456789; break;
			case 42 : ans = 3456789; break;
			case 43 : ans = 13456789; break;
			case 44 : ans = 23456789; break;
			case 45 : ans = 123456789; break;
		}
		printf("%d\n",ans);
		return ;
	}
	
	int answer = -1;
	for(int i = 1;i < nax; ++i){
		if(isValid(i, x)){
			answer = i;
			break;
		}
	}
	
	printf("%d\n",answer);
}



int main(){
	int tt;
	scanf("%d",&tt);
	
	for(int i = 0; i < tt; ++i){
		solve();
	}
	
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}
