#include<bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * If Gcd(a, b) = d then Gcd(a, d) = d and Gcd(b, d) = d and moreover d <= min(a, b). So for each element of the array if it's not divisible by the minimum
 * Then they should be at their correct sorted position because we can never swap them . (What about Divisibles ? Remember about swap sort ).
 */

void solve(){	
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	
	int mini = (int)2e9;
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
		mini = min(mini, arr[i]);
	}
	
	vector<int> sorted = arr;
	sort(sorted.begin() , sorted.end());
	
	for(int i = 0; i < n; ++i){
		if(arr[i] % mini && arr[i] != sorted[i]){
			puts("No");
			return;
		}
	}
	puts("Yes");
}


int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}	
	return 0;	
}
