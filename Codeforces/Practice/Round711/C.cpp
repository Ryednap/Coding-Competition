#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif
using vi = std :: vector<int>;
using ll = long long;
const int mod = (int)1e9 + 7;

int Mul (ll a, ll b) {
	return ((a * b) % mod + mod) % mod;
}
ll Sub(ll a, ll b) {
	return ((a - b) % mod + mod) %mod;
}
ll Add(ll a, ll b) {
	return ((a + b)% mod + mod) % mod;
}

int main() {
	vi v = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23, 29, 31, 37, 41};
	const int n = (int)v.size();
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		ll x; scanf("%lld", &x);
		ll answer = 2 * (x - x / 2);
		for(int i = 1; i < n; ++i) {
			ll a = (x - x / v[i]) - 1;
			for(int j = 1; j < (1 << (n - 1)) ; ++j) {
				ll prod = 1;
				for(int k = 0; k < n - 1; ++k) {
					if(j & (1 << k)) {
						prod *= v[k];
					}
				}
				prod *= v[i];
				a -= (x / prod);
			}
			debug() << owo(v[i]) owo(a);
			answer = Add(answer, Mul(v[i], a));
		}
		printf("%lld\n", answer);
	}
	return 0;
}