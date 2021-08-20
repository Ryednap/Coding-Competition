
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int,int>;
#define F first
#define S second

void solve(){
	int n;
	scanf("%d",&n);
	int arr[n];
	bool ok = false;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
		if(arr[i] != 0) ok = true;
		sum += arr[i];
	}
	
	if(!ok){
		puts("NO");
		return;
	}
	
	puts("YES");
	if(sum != 0){
		puts("1");
		printf("%d %d\n", 1, n);
		return ;
	} else {
		int p1 = 0;
		puts("2");
		for(int i = 0;i < n; ++i){
			p1 += arr[i];
			sum -= arr[i];
			if(p1 != 0 && sum != 0){
	
				printf("%d %d\n", 1, i + 2);
				printf("%d %d", i + 3, n);
				return ;
			}
		}
	}
	assert(false);
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
