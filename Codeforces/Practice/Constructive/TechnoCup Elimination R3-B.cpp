
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int,int>;
#define X first
#define Y second

void solve(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}
	
	vector<bool> used(n + 1);
	int ans[n];
	ans[0] = arr[0];
	used[ans[0]] = true;
	
	for(int i = 1; i < n; ++i){
		if(arr[i] != arr[i - 1]){
			ans[i] = arr[i];
			used[ans[i]] = 1;
		}
	}
	
	vector<int> rem;
	for(int i = 1; i <= n; ++i){
		if(!used[i]) rem.push_back(i);
	}
	reverse(rem.begin(), rem.end());

	for(int i = 1; i < n; ++i){
		if(arr[i] == arr[i - 1]){
			int x = rem.back();
			if(x > arr[i - 1]){
				puts("-1");
				return;
			} else {
				rem.pop_back();
				ans[i] = x;
			}
		}
	}
	
	for(int i = 0; i < n; ++i){
		printf("%d ", ans[i]);
	}
	puts("");
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
