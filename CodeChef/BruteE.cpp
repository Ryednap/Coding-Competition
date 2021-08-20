#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int nax = 2e8 + 10;
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
set<int> numbers;

bool isPalindrome(int n) {
	std :: string s = to_string(n);
	const int len = (int)s.length();
	if(!(len & 1)) return false;
	for(int i = 0; i < len / 2; ++i) {
		if(s[i] != s[len - 1 - i]) return false;
	}
	return true;
}

ll Add(ll a, ll b) {
	return (a + b) % mod;
}

ll Mul(ll a, ll b) {
	return (a * b) % mod;
}

ll powMod(ll a, ll b) {
	ll res = 1;
	for(; b; b >>= 1) {
		if(b & 1) {
			res = Mul(res, a);
		}
		a = Mul(a, a);
	}
	return res%mod;
}

int main() {
	for(int i = 0; i < nax; ++i) {
		if(isPalindrome(i)) numbers.insert(i);
	}

	vector<ll> v (numbers.begin(), numbers.end());
	vector<ll> pref(v.size() + 1, 0);
	for(int i = 1; i < v.size(); ++i) {
		pref[i] = Add(pref[i - 1], v[i]);
	}

	int qq;
	scanf("%d",&qq);
	while (qq--) {	
		int L, R;
		scanf("%d %d", &L, &R);
		ll answer = 1, power = 0;
		for(int i = L + 1; i <= R; ++i) {
			answer = Mul(answer, powMod(v[L], v[i]));
			power = Add(power, v[i]);
		}
		debug() << owo(v[L]) owo(v[R]) owo(power);
		printf("%lld\n", answer);
	}
}
