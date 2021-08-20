#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
	This is a nice problem :-
	Claim1 :- It's always beneficial to 

*/


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<long long> dp;
	
	for(int i = 1; i <= n; ++i) {
		long long x; scanf("%lld", &x);
		x = i * (long long)m - x;
		debug() << owo(x);
		if(x < 0) continue;
		if(dp.empty() || x >= dp.back()) {
			dp.push_back(x);
		} else {
			*upper_bound(dp.begin(), dp.end(), x) = x;
		}
	}
	
	printf("%d\n", n - (int)dp.size());
    return 0;
}
