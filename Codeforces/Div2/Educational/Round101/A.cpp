#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Mistake :- Not reading the problem statement properly (i don't know how many mistakes i have made becuase of this)


void solve(){
	string str;
	cin >> str;
	if( (int)str.length() & 1) puts("No");
	else if(str[0] == ')' || str.back() == '(') puts("No");
	else puts("Yes");	
}

int main(){
	int tt;
	scanf("%d",&tt);	
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;
}
