#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int nax = 1e5 + 100;
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
set<ll> numbers;

bool check() {
	return ((int)numbers.size() < nax);
}

ll Add(ll a, ll b) {
	return ((a + b) % mod + mod)%mod;
}

ll Mul(ll a, ll b) {
	return ((a%mod * b%mod))%mod;
}
ll Sub(ll a, ll b) {
	return ((a - b) % mod + mod)%mod;
}

long long powMod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = Mul(res, a);
        a = Mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
	for(int i = 0; check() ; ++i)  {
		for(char middle = '0'; middle <= '9'; ++middle){
			int Zero = 0;
			function < void (string) > generator = [&] (string s) {
				if(!check()) return;

				if((int)s.length() == i) {
					string rev = s; reverse(rev.begin(), rev.end());
					string num = s + middle + rev;
					numbers.insert(stoll(num));
					return;
				}

				for(char digit = '1' - Zero; digit <= '9'; ++digit) {
					Zero = 1;
					generator(s + digit);
				}
			};
			generator("");
		}
	}
	vector<ll> v (numbers.begin(), numbers.end());

	vector<ll> pref(nax, 0);
	for(int i = 1; i < nax; ++i) {
		pref[i] = Add(pref[i - 1], v[i]);
	}
	int qq;
	scanf("%d",&qq);

	while (qq--) {	
		int L, R;
		scanf("%d %d", &L, &R);
		ll power = Sub(pref[R] , pref[L]);
		ll answer = powMod(v[L], power);
		printf("%lld\n", answer);
	}

	return 0;
}
