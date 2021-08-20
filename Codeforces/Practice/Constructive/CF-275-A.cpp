
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Real constructive problem. Now i have a nice proof. Pick smallest k numbers 1,2,3....k then sigm(k) < n . i.e we can never have a problem in which k
 * doesnot satisfies the property . Now this makes the problem really easy. We will try to construct the solution in such a way that 1 + k, a - (k - 1),
 * b + (k - 2).... And after k = 0 we just need to keep printing the next unused permutation element. Proof that it always leads to solution and is unique. =>
 * 
 * Let a = 1, b = a + k, c = b - (k - 1). Now This sequence is unique why ? Think like spiral , well spiral never intersect each other. So a < b > c < d...
 * Also this restriction Permits one thing that after k is 0 the next sequence difference is either 1 or one of the used difference. 
 */

void solve(){
	int n, k;
	scanf("%d %d",&n,&k);
	vector<int> ans(n), used(n + 1);
	ans[0] = used[1] = 1;
	int par = 0;
	
	for(int i = 1; i < n; ++i){
		if(k == 0){
			for(int j = 1; j <= n; ++j){
				if(!used[j]){
					ans[i++] = j;
				}
			}
			break;
		}
		
		ans[i] = ans[i - 1] + k * (par ? -1 : 1);
		assert(!used[ans[i]]);
		used[ans[i]] = 1;
		--k;
		par ^= 1;
	}
	
	for(int i = 0; i < n ; ++i){
		printf("%d ", ans[i]);
	}
		
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
