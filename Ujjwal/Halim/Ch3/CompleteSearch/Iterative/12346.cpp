#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// An easy approach O(2 ^ n) per test - case at worst.

using pii = pair<long long, long long>;
#define f first
#define s second

int main() {
	int n;
	scanf("%d", &n);
	int Gates[n][2];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			scanf("%d", &Gates[i][j]);
		}
	}
	
	vector<pii> precomp;
	
	for(int i = 0; i < (1 << n); ++i) {
		long long cost = 0, volume = 0;
		for(int j = 0; j < n; ++j) {
			if(i & (1 << j)) {
				cost += Gates[j][1];
				volume += Gates[j][0];
			}
		}
		precomp.emplace_back(volume, cost);
	}
	
	sort(precomp.rbegin(), precomp.rend());
	
	int qq;
	scanf("%d", &qq);
	for(int tt = 0; tt < qq; ++tt) {
		int m, t;
		scanf("%d %d", &m, &t);
		long long answer = 1e18L;
		
		for(auto p : precomp) {
			if(p.f * t < m) break;
			answer = min(answer, p.s);
		}
		if(answer != 1e18L) printf("Case %d: %lld\n", tt + 1, answer);
		else printf("Case %d: IMPOSSIBLE\n", tt + 1);
	}
	return 0;
}
