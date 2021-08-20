#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


void solve(){
	int n;
	scanf("%d",&n);
	
	int arr[n];
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}
	
	for(int i = 1; i < (int)2e3; ++i){
		map<int, int> done;
		for(int j = 0; j < n; ++j){
			done[i ^ arr[j] ] = 1;
		}
		bool ok = true;
		for(int j = 0;j < n; ++j){
			if(!done[ arr[j] ]) ok = false;
		}
		if(ok){
			printf("%d\n",i);
			return;
		}
	}
	
	puts("-1");	
}


int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0;i < tt; ++i){
		solve();
	}
	
	return 0;
}
