#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

void solve(){
	string str;
	cin >> str;
	
	const int n = (int)str.length();
	
	bool zero , one ;
	zero = one = false;
	for(int i = 0; i < n; ++i){
		char ch = str[i];
		if(ch == '0'){
			if(one){
				puts("3 1");
				one = false;
			} else {
				puts("1 1");
				one = true;
			}
			
		} else {
			if(zero) {
				puts("4 1");
				zero = false;
			} else {
				puts("4 3");
				zero = true;	
			}
		}
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
