#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * if we have to divide the array into k odd segments note that depending on k we will end up with even or odd sum . so the parity of the k and the sum  
 * of array elements must be same. Now even after that it's not always possible because what makes the sum odd is odd numbers if the number of odd no. is
 * less than k then we can never do that so check it. else print the (k - 1) odd sum partion and then last segment is auto odd. 
 */

void solve(){
	int n, k;
	scanf("%d%d",&n, &k);
	
	long long sum = 0;
	int arr[n];
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	
	
	if((k & 1) == (sum & 1)){
		vector<int> ans;
		long long cur = 0;
		for(int i = 0; i < n && k > 1 ; ++i){
			cur += arr[i];
			if(cur & 1){
				ans.push_back(i + 1);
				cur = 0;
				--k;
			}
		}
		if(k != 1) puts("No");
		else {
			puts("YES");
			for(int x : ans) printf("%d ", x);
			printf("%d\n", n);
		}
	} else puts("NO");
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
