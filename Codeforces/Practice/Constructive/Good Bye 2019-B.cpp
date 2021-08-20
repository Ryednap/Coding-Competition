//For an array a of integers let's denote its maximal element as max(a), and minimal as min(a). We will call an array a of k integers interesting if max(a)−min(a)≥k. For example, array [1,3,4,3] isn't interesting as max(a)−min(a)=4−1=3<4 while array [7,3,0,4,3] is as max(a)−min(a)=7−0=7≥5.
//You are given an array a of n integers. Find some interesting nonempty subarray of a, or tell that it doesn't exist.
//An array b is a subarray of an array a if b can be obtained from a by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. In particular, an array is a subarray of itself.

#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Let's prove the following thing :- If the answer exists then there must exist a consecutive element such that there difference is >= 2. Now this is easy
 * as if this is not true then all the elements differ by 1 means all the integers are consecutive and in this case there does'nt exist and length of size
 * |S| such that the condition holds as the difference is always going to be |S| - 1.
 */

void solve(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i < n; ++i){
		scanf("%d",&arr[i]);
	}
	
	for(int i = 0; i < n - 1; ++i){
		if(abs(arr[i] - arr[i + 1]) >= 2){
			puts("YES");
			printf("%d %d\n", i + 1, i + 2);
			return;
		}
	}
	puts("NO");
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
