#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

/*
 * 3 WA
 * 
 * 1st :- Due to not including when it's not possible for t to become 0 actally they haven't given sample for this case
 * 2nd :- Was due to preference of maximum burgers rather than minimum beer time
 * 3rd :- Because WA in 2nd attempt I neglected that we need dp so I did greedy in which always take smallest burger time, WA due to 17 18 100 case.
 */

const int nax = 1e4 + 10;
long long dp[nax];
const long long OO = 1e7;

int m, n, t;

using pii = pair<long long, long long>;
pii bp[nax];

long long Brute(int i) {
	if(i == 0) return 0;
	if(i < 0) return -OO;
	
	long long & ans = dp[i];
	if(ans != -1) return ans;
	return ans = max(Brute(i - n) + 1,  Brute(i - m) + 1);
}

pii Max(pii a, pii b) {
	
	if(a.s == b.s) {
		if(b.f > a.f) return b;
		else return a;
		
	} else if(a.s > b.s) return b;
	else return a;
} 

pii Frute(int i) {
	assert(i - min(n, m) != 0);
	if(i - min(n, m) < 0) return make_pair(0, i);
	
	pii & ans = bp[i];
	if(ans.f != -1) return ans;
	
	if(i - n > 0) ans = Max(Frute(i - n), ans);
	if(i - m > 0) ans = Max(Frute(i - m), ans);
	
	ans.f += 1;
	return ans;
}

int main() {
	
	while (scanf("%d %d %d", &m, &n, &t) != EOF) {
		memset(dp, -1, sizeof(dp));
		long long ans = Brute(t);
		if(ans > 0) printf("%lld\n", ans);
		else {
			for(int i = 0; i < nax; ++i) {
				bp[i] = make_pair(-1, OO);
			}
			auto res = Frute(t);
			printf("%lld %lld\n", res.f, res.s);
		}
	}
	
	return 0;
}
