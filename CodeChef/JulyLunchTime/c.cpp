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

vi readArray(int n) {
	vi v(n);
	for (auto & x : v) {
		cin >> x;
	}
	return v;
}


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, k, s;
		scanf("%d %d %d", &n, &k,&s);
		vi a = readArray(n);
		vi b(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			b[i] += b[i - 1] + a[i - 1];
		}
		--k;
		int ans = 0;
		for (int i = 0; i < n; ++i){
			int lo = 0, hi = n - 1;
			int pos = -1;
			while (lo <= hi) {
				int m = (lo + hi) >> 1;
				ll sumHere = b[m + 1] - b[i];
				if(sumHere <= 1ll * k *s) {
					pos = m;
					lo = m + 1;
				} else hi = m - 1;
			}
			debug() << owo(1ll *k * s) owo(b[pos + 1] - b[i]) owo(pos);
			ans = max(ans, pos - i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}