#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
 * A basic implementation based problem.
 */

void solve(){
	int n;
	scanf("%d",&n);
	
	int B[n];
	for(int i = 0; i < n; ++i){
		scanf("%d",&B[i]);
	}
	
	int turn = 1;
	for(int i = 0, j = n - 1; i <= j;  ){
		if(turn & 1) printf("%d ",B[i++]);
		else printf("%d ", B[j--]);
		turn ^= 1;
	}
	puts("");		
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
