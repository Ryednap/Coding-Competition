#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Greedy problem. I missed this so bad of me. The problem i faced during the contest was that i started to think from upper thing and mind got flooded with too much idea
// of binary search, O(N^3) dp, so on.

const int nax = (int)1e4;

int arr[nax];
int sum = 0;
int n;

bool F( int x ){
	x = n - x;

	if(sum % x != 0) return false;
	const int val = sum / x;
	int curr = 0;
	for(int i = 0; i < n; ++i){
		curr += arr[i];
		if(curr == val){
			curr = 0;
			
		} else if(curr > val) return false;
	}

	return curr == 0;
}

void solve(){
	scanf("%d",&n);
	
	sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	
	for(int i = 0; i < n; ++i){
		if(F(i)){
			printf("%d\n",i);
			return;
		}
	}
	
	puts("-1");
	
}



int main(){
	int tt;
	scanf("%d",&tt);
	
	for(int i = 0; i < tt; ++i){
		solve();
	}
	
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}
