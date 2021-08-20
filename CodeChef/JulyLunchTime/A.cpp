#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
using vi = std::vector<ll> ;
using pii = pair<ll, ll>;

#define f first
#define s second

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		unordered_map<int, int> mapper;
		for (int i =0 ; i < n; ++i) {
			int x; scanf("%d", &x);
			mapper[x]++;
		}
		ll ans = 0;
		for (auto p : mapper) {
			ans += 1ll * p.s * (n - p.s);
		}
		printf("%lld\n", ans);
	}
	return 0;
}