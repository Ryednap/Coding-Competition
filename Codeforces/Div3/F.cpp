#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Nice event based problem. We will try to maximise the set size . So for each element i.e for each event we will find what is the maximum number of event it can hold
// So now let's sort the event by L and then Using the binary search find the largest index to the right of the current event such that the predicate R <= L_current is true
// Now we need to find all the event to the left of the current event such that L_current <= R. Now interestingly it's same as the previous just inverse of it . Now if
// we notice that will doing the first part all the number in the range [i + 1, our found index from BS] will have our current event in their left. So let's do the range
// sum for it now combine them to get the answer.

using pii = pair<int,int>;
#define L first
#define R second

void solve(){
	int n;
	scanf("%d",&n);
	
	pii event[n];
	for(int i = 0; i < n; ++i){
		scanf("%d%d",&event[i].L, &event[i].R);
	}
	
	sort(event, event + n);
	

	vector<int> dip(n + 1);
	vector<int> ans(n);
	for(int i = 0; i < n; ++i){
		int lo = i + 1, hi = n - 1;
		int range = -1;
		
		while(lo <= hi){
			int mid = (lo + hi)/2;
			if( event[mid].L <= event[i].R ){
				lo = mid + 1;
				range = mid;
				
			} else hi = mid - 1;
		}
		
		if(range == -1) continue;
		ans[i] = range - i;
		dip[i + 1] += 1;
		dip[range + 1] -= 1;
	}
	
	
	for(int i = 1; i <= n; ++i) dip[i] += dip[i - 1];
	int answer = 0;
	for(int i = 0; i < n; ++i){
		answer = max(answer, dip[i] + ans[i] + 1);
	}
	printf("%d\n",n - answer);
}

int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}
	
	return 0;
}
