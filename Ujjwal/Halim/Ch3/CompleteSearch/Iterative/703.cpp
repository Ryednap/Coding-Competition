#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;

// Double mistakes :

// There is a rule for tie 
// For tie there is sorted normal form unlike victory which has order rather than sorting
// like for {i, j, k} for victory there is like directed graph but for tie it's like undirected .

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<vi> w(n, vi(n));
		
		for(int i = 0; i < n ; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d",&w[i][j]);
			}
		}
		
		set<vector<int>> ans;
		
		auto Get = [&] (int a, int b, int c) {
			vi p = {a, b, c};
			vi q = {c, a, b};
			vi r = {b, c, a};
			for(auto x : {p, q, r}) {
				if(is_sorted(x.begin(), x.end()) || is_sorted(x.rbegin(), x.rend())) return x;
			}
			assert(false);
			return vi();
		};
		
		auto Victory = [&](int a, int b) {
			return w[a][b];
		};
		
		auto Tie = [&] (int a, int b) {
			return !w[a][b] && !w[b][a];
		};
		
		for(int i = 0 ; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int k = 0; k < n; ++k) {
					if(i == j || i == k || j == k) continue;
	
					if(Victory(i, j) && Victory(j, k) && Victory(k, i)) {
						vector<int> v = Get(i, j, k);
						ans.insert(v);
					}
					else if(Tie(i, j) && Tie(j, k) && Tie(k, i)) {
						vector<int> v = {i, j, k};
						sort(v.begin(), v.end());
						ans.insert(v);
					}
					
				}
			}
		}
		
		printf("%d\n", (int)ans.size());
		for(auto v : ans) {
			printf("%d %d %d\n", v[0] + 1, v[1] + 1, v[2] + 1);
		}
		
	}
		
	return 0;
}
