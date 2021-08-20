#include <bits/stdc++.h>

using namespace std;
#define sz(x) ((int)x.size())

int main() {
	int n;
	scanf("%d", &n);
	vector<int> edges[n + 1];
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	int ans = 0;
	for(int i = 2; i <= n; ++i) {
		if(sz(edges[i]) == 1) {
			int par = edges[i][0];
			if(par == 1) continue; // 1 mistake here 1 Wa
			if(sz(edges[par]) == 2) ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
