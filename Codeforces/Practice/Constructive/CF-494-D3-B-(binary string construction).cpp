#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
 * The best constructivness is start from the character that is maximum and alternatively put characters until x - 1 then based on the last character
 * put the remaining characters.
 * 
 */

void solve(){
	int a, b, x;
	scanf("%d %d %d",&a, &b, &x);
	
	array<char, 2> ar = {'0', '1'};
	
	string ans;
	int t = (a > b ? 0 : 1);
	if(a > b) --a;
	else --b;
	ans += ar[t++];
	int cnt = 0;
	
	while(cnt < x - 1){
		++cnt;
		char ch = ar[t % 2];
		ans += ch;
		++t;
		if(ch == '0') --a;
		else --b;
	}
	
	printf("%s",ans.c_str());
	string one = string(b, '1');
	string zero = string(a, '0');
	if(ans.back() == '1'){
		printf("%s%s",one.c_str(), zero.c_str());
	} else printf("%s%s",zero.c_str(), one.c_str());
	
}

int main(){
	int tt;
	tt = 1;
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;	
}
