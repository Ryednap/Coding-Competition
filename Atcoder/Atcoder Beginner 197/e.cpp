#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second


int main() {
	int n;
	scanf("%d", &n);
	map<int, vector<int>> mapper;
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		mapper[b].push_back(a);
	}
	
	vector<pii> v;
	
	for(auto p : mapper) {
		int mini = (int)1e9, maxi = -(int)1e9;
		for(auto x : p.s) {
			mini = min(mini, x);
			maxi = max(maxi, x);
		}
		v.emplace_back(mini, maxi);
	}
	
	const int m = (int)v.size();
	//debug() << owo(v);
	
	long long dp[m + 1][2];
	dp[0][0] = abs(v[0].f) + abs(v[0].s - v[0].f);
	dp[0][1] = abs(v[0].s) + abs(v[0].s - v[0].f);
	
	auto Get = [&] (int i, int x) {
		return min(dp[i - 1][0] + abs(x - v[i - 1].s), dp[i - 1][1] + abs(x - v[i - 1].f));
	};
	
	for(int i = 1; i < m; ++i) {
		dp[i][0] = Get(i, v[i].f) + abs(v[i].s - v[i].f);
		dp[i][1] = Get(i, v[i].s) + abs(v[i].s - v[i].f);
	}
	
	long long answer = min(dp[m - 1][0] + abs(v[m - 1].s), dp[m - 1][1] + abs(v[m - 1].f));
	printf("%lld\n", answer);
	return 0;
}
