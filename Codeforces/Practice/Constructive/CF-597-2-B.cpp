#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

void solve(){
	int n;
	scanf("%d",&n);
	//Rock Paper Scissor
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	
	char Bob[n];
	scanf("%s",Bob);
	
	int r = 0, p = 0, s = 0;
	for(int i = 0; i < n; ++i){
		char ch = Bob[i];
		if(ch == 'R') ++r;
		else if(ch == 'P') ++p;
		else ++s;
	}
	
	if(min(r, b) + min(p, c) + min(s, a) >= (n + 1) /2 ){
		string ans(n, '_');
		for(int i = 0; i < n; ++i){
			char ch = Bob[i];
			if(ch == 'R'){
				if(b) ans[i] = 'P', --b;
			} else if(ch == 'P'){
				if(c) ans[i] = 'S', --c;
			} else {
				if(a) ans[i] = 'R', --a;
			}
		}
		
		for(char &ch : ans){
			if(ch == '_'){
				if(a) ch = 'R' , --a;
				else if(b) ch = 'P' , --b;
				else ch = 'S', --c;
			}
		}
		puts("YES");
		printf("%s\n", ans.c_str());
	
	} else puts("NO");
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
