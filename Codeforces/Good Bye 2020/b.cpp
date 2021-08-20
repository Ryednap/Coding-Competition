#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


void solve(){
	int n;
	scanf("%d",&n);
	map<int, int> m;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d",&x);
		m[x]++;
	}
	
	vector<pair<int, int>> v (m.begin() , m.end());
	const int k = (int)v.size();
	
	set<int> ans;
	int prev = -1;
	for(int i = 0; i < k; ++i){
		auto [x,cnt] = v[i];
		if(cnt > 1) {
			if(prev == x){
				ans.insert(x + 1);
				
			} else {
				ans.insert(x);
				ans.insert(x + 1);
			}	
				prev = x + 1;
					
		} else {
			if(prev == x){
				ans.insert(x + 1);
				prev = x + 1;
				
			} else {
				ans.insert(x);
				prev = x;
			}
		}
	}

	printf("%d\n", (int)ans.size());
}

int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;
}
