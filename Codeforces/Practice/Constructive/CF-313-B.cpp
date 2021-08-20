
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int,int>;
#define X first
#define Y second

void solve(){
	array<int, 2> a, b, c;
	scanf("%d %d", &a[0], &a[1]);
	scanf("%d %d", &b[0], &b[1]);
	scanf("%d %d", &c[0], &c[1]);
	
	bool ok = false;
	
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j){
			int len = max(b[i], c[j]);
			int width = b[i ^ 1] + c[j ^ 1];
			if(a[0] >= len && a[1] >= width){
				ok = true;
			}
			if(a[0] >= width && a[1] >= len){
				ok = true;
			}
		}
	}
	puts(ok ? "Yes" : "No");
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
