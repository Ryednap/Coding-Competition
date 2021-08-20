#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


void solve(){
	string str;
	cin >> str;
	
	int ans = 0;
	const int n = (int)str.length();
	for(int i = 0; i < n; ++i){
		if(i + 1 < n && str[i] == str[i + 1]){
			int pos = i + 1;
			for(char ch = 'a' ; ch <= 'z'; ++ch){
				bool ok = true;
				if(pos && ch == str[pos - 1]) ok = false;
				if(pos - 1 && ch == str[pos -1]) ok = false;
				if(pos + 1 < n && ch == str[pos + 1]) ok = false;
				if(pos + 2 < n && ch == str[pos + 2]) ok = false;
				if(ok) {
					str[pos] = ch;
					++ans;
					break;
				}
			}
			
		} 
		if(i + 2 < n && str[i] == str[i + 2]){
			int pos = i + 2;
			for(char ch = 'a' ; ch <= 'z'; ++ch){
				bool ok = true;
				if(pos && ch == str[pos - 1]) ok = false;
				if(pos - 1 && ch == str[pos -1]) ok = false;
				if(pos + 1 < n && ch == str[pos + 1]) ok = false;
				if(pos + 2 < n && ch == str[pos + 2]) ok = false;
				if(ok) {
					str[pos] = ch;
					++ans;
					break;
				}
			}
				
		}
	}
	debug() << owo(str);
	printf("%d\n", ans);
		
			
}

int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;
}
