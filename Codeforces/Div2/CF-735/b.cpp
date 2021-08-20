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
		int n, k;
		scanf("%d %d", &n, &k);
		int a[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		ll ans = -1e18L;
		for(int i = n - 1; i >= max(0, n - 400); --i)
			for(int j = i - 1; j >= max(0, n - 400); --j)
				ans = max(ans, 1ll*(i + 1)*(j + 1) - k*(a[i]|a[j]));
		printf("%lld\n",ans);
	}
	return 0;
}