#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;

#define f first
#define s second

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		int a[n];
		ll ans = 0;
		ll prev; scanf("%lld", &prev);
		for(int i = 1; i < n; ++i) {
			int x; scanf("%d", &x);
			ans = max(ans, prev * x);
			prev = x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}