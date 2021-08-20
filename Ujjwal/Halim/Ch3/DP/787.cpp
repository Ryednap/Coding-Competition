#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
using pll = pair<ll, ll>;
const ll OO = 1e18L;

#define f first
#define s second

ll Get(ll x, pll p) {
	if(p.f == OO || p.s == -OO) return -OO;
	//debug() << owo(x) owo(p);
	assert(p.f != 0 && p.s != 0);
	assert(x % p.f == 0);
	assert(x % p.s == 0);
	return max(x / p.f, x / p.s);
}

ll Foo(const vector<int> & v) {
	pll pos, neg;
	pos = {OO, 1};
	neg = {-1, -OO};
	
	const int n = (int)v.size();
	ll pref[n + 1];
	pref[0] = 1;
	for(int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] * v[i - 1];
	}
	
	ll answer = -OO;
	for(int i = 0; i <= n; ++i) {
		answer = max(Get(pref[i], pos), answer);
		answer = max(Get(pref[i], neg), answer);
		
		if(pref[i] > 0) {
			pos.f = min(pos.f, pref[i]);
			pos.s = max(pos.s, pref[i]);
			
		} else {
			neg.f = min(neg.f, pref[i]);
			neg.s = max(neg.s, pref[i]);
		}
	}
	return answer;
}

int main() {
	int x;
	while (scanf("%d", &x) != EOF) {
		vector<vector<int>> arr;
		vector<int> v;
		if(x) v.push_back(x);
		bool hasZero = false;
		while (scanf("%d", &x) && x != -999999) {
			if(x == 0) {
				if(!v.empty()) arr.push_back(v);
				v.clear();
				hasZero = true;
			} else {
				v.push_back(x);
			}
		}
		
		if(!v.empty()) arr.push_back(v);
		ll answer = -OO;
		for(auto vec : arr) {
			answer = max(answer, Foo(vec));
		}
		
		if(hasZero) answer = max(answer, 0LL);
		printf("%lld\n", answer);
	}
	
	return 0;
}


// Two mistakes : First was thought use of BigInteger later after getting 4 runtime eror.
// The first x was pushed back in v without checking for 0

/*
 * The idea is to first partititon the array on the zero and have a check mark for 0
 * then for each parititon check the max sub-array prod.
 * For checking prod maintain two seperate positive and negative min and max and then check for each partial prod with both pos and neg min and max.
 * based on check check the max of 0 and the acquired maximum.
 * 
 */ 
