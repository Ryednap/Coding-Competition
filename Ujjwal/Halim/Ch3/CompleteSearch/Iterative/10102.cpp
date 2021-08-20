#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

// O(n ^ 4) in the worst case
// We can do better using binary search and sorting in O(n ^ 2 logn)
// Sort the points based on the manhattan distance from 0, 0 and then for each one we can use two pointer or binary search.
// Check this idea :- todo

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		string mat[n];
		for(int i = 0; i < n; ++i) {
			cin >> mat[i];
		}
		
		vector<pii> three, one;
		for(int i = 0 ; i < n; ++i) {
			for(int j = 0 ; j < n; ++j) {
				if(mat[i][j] == '1') one.push_back({i, j});
				if(mat[i][j] == '3') three.push_back({i, j});
			}
		}
		int ans = 0;
		
		for(auto a : one) {
			int mini = (int)1e9 + 10;
			for(auto b : three) {
				int d = abs(a.f - b.f) + abs(a.s - b.s);
				mini = min(mini, d);
			}
			ans = max(ans, mini);
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
