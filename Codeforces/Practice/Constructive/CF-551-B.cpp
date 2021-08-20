
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * RTP :- If i put the mini then the soln is valid.
 */

void solve(){
	int n, m, h;
	scanf("%d %d %d",&n, &m, &h);
	int col[m], row[n];
	for(int i = 0; i < m; ++i){
		scanf("%d",&col[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d",&row[i]);
	}
	

	for(int i = 0; i < n; ++i){
		for(int j = 0;j < m; ++j){
			int x;
			scanf("%d",&x);
			if(x > 0){
				printf("%d ", min(row[i], col[j]));
			
			} else printf("0 ");
		}
		puts("");
	}
				
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
