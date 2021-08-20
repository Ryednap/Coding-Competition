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
		vi a(n);
		for (int i = 0; i< n; ++i) {
			scanf("%lld", &a[i]);
		}
		sort(a.begin(), a.end());
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			int pos = -1;
			int lo = 0,hi = n - 1;
			while (lo <= hi) {
				int m = (lo + hi) >> 1;
				if(a[i] > a[m]) {
					lo = m + 1;
					pos = m;
				} else hi = m - 1;
			}
			ans += pos + 1;
		}
		printf("%lld\n",ans * 2);
	}
	return 0;
}