#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int mat[n][n];
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d", &mat[i][j]);
			}
		}
		
		set<vector<int>> ans;
		
		for(int i = 0; i < n; ++i) { // for each node
			for(int j = 0; j < n; ++j) { // for each second node
				if(!mat[i][j] || i == j) continue;
				for(int k = 0; k < n; ++k) { // for each third node
					if(!mat[j][k] || !mat[k][i] || j == k || k == i) continue;
					vector<int> a = {i, j, k};
					vector<int> b = {j, k, i};
					vector<int> c = {k, i, j};
					ans.insert(a);
					ans.erase(b);
					ans.erase(c);
				}
			}
		}
		
		set<vector<int>> Final;
		
		for(auto v : ans) {
			auto a = {v[0], v[1], v[2]};
			auto b = {v[2], v[0], v[1]};
			auto c = {v[1], v[2], v[0]};
			for(vector<int> x : {a, b, c}) {
				if(is_sorted(x.begin(), x.end()) || is_sorted(x.rbegin(), x.rend())) {
					Final.insert(x);
					break;
				}
			}
		}
		for(auto x : Final) {
			printf("%d %d %d\n", x[0] + 1, x[1] + 1, x[2] + 1);
		}
		printf("total:%d\n", (int)ans.size());
		puts("");
	}
	return 0;
}
