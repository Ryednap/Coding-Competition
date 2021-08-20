#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Similar implementation based problem. I wasted too much time for shit trying to code better.
 * 
 */

void solve(){
	int n;
	scanf("%d",&n);
	
	char S[n];
	scanf("%s",S);
	
	const string Match = "2020";
	
	int i = 0, j = 3;
	int cnt = 0;
	for(int a = 0, b = n - 1; S[a] == Match[i] || S[b] == Match[j];){
		if(S[a] == Match[i]){
			++a;
			++i;
			++cnt;
		} else if(S[b] == Match[j]){
			--b;
			--j;
			++cnt;
		} else break;
	}
	if(cnt >= 4) puts("YES");
	else puts("NO");
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
