#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Remove the x larger than W they are of no use . Now if W is less than minimum or total sum is less than half then no chance . Else there's always a 
 * chance becuase now each element is either <= h or >= h. Now let's start picking from largest. If the largest >= h then we are done else now we know
 * that largest and all elements are smaller if y <= x/2 then 2y <= x so we can now greedily pick until we hit the mark.
 */

#define F first
#define S second

void solve(){
	int n;
	long long W;
	scanf("%d %lld",&n, &W);
	long long h = (W + 1)/2;
	
	vector<pair<int ,int > > arr;
	long long sum = 0;
	for(int i = 0; i < n; ++i){	
		int x;
		scanf("%d",&x);
		if(x > W) continue;
		arr.push_back({x,i});
		sum += x;
	}
	
	sort(arr.begin(), arr.end());
	
	if((int)arr.size() == 0) puts("-1");
	else if(W < arr[0].F || sum < h ) puts("-1");
	else {
		vector<int> ans;
		long long tot = 0;
		for(int i = (int)arr.size() - 1; i >= 0; --i){
			ans.push_back(arr[i].S + 1);
			tot += arr[i].F;
			if(tot >= h) break;
		}
		assert(tot <= W && tot >= h);
		printf("%d\n", (int)ans.size());
		for(int x : ans){
			printf("%d ", x);
		}
		puts("");
	}
}


int main(){
	int tt;
	scanf("%d" , &tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;	
}
