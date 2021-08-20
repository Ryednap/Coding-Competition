#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

void solve(){
	int n;
	scanf("%d",&n);
	
	if(n == 1) puts("a");
	else if(n == 2) puts("ab");
	else {
	
		string ans = "aabbaabbaabb";
		int q = n/(int)ans.length();
		int r = n % (int)ans.length();
		for(int i = 0; i < q; ++i) printf("%s", ans.c_str());
		for(int i = 0; i < r; ++i) printf("%c", ans[i]);
	}
}
			


int main(){
	int tt;
	tt = 1;
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;	
}
