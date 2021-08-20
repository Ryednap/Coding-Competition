#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif



int main() {
	int t, n;
	while (scanf("%d %d", &t, &n)) {
		if(!t && !n) break;
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		set<vector<int>> res;
		for(int i = 0; i < (1 << n); ++i) {
			vector<int> v;
			int sum = 0;
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) {
					sum += arr[j];
					v.push_back(arr[j]);
				}
			}
			if(sum == t) {
				sort(v.rbegin(), v.rend());
				res.insert(v);
			}
		}
		
		vector<vector<int>> ans = vector<vector<int>> (res.begin(), res.end());
		sort(ans.rbegin(), ans.rend());
		printf("Sums of %d:\n", t);
		
		if((int)ans.size() == 0) {
			puts("NONE");
		} else {
	
				for(auto v : ans) {
				printf("%d", v[0]);
				for(int i = 1; i < (int)v.size(); ++i) {
					printf("+%d", v[i]);
				}
				puts("");
			}
		}
	}
	return 0;
}
