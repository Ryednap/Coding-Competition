#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

void Solve(){
	string str;
	cin >> str;
	int x, y;
	scanf("%d %d",&x,&y);
	
	long long answer = (int)1e14;
	const int n = (int)str.length();
	int zero[n + 1] = {0}, one[n + 1] = {0};
	
	int mark = 0;
	for(int i = 0; i < n; ++i){
		zero[i + 1] = zero[i] + (str[i] == '0');
		one[i + 1] = one[i] + (str[i] == '1');
		mark += (str[i] == '?');
	}
	
	for(int i = 0; i < n; ++i){
		if(str[i] == '?'){
			if(x < y) answer = min(answer, 
	
	printf("%lld\n", answer);
	
}

int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		Solve();
	}
	return 0;
}
