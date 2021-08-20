#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Multi-concept problem nice :-
// Number theroy, Search, binary search.

const int nax = (int)1e6 + 1;
int main() {
	// precomputation unoptimized.
	vector<int> primes;
	bool used[nax] = {false};
	for(int i = 2; i < nax; ++i) {
		if(used[i]) continue;
		primes.push_back(i);
		for(int j = 2; j * i < nax; ++j) {
			used[j * i] = true;
		}
	}
	
	
	int n, tt = 0;
	while (scanf("%d", &n) && n) {
		long long count = 0;
		for(auto lo = primes.begin(); lo != primes.end(); ++lo) {
			if(*lo >= n) break;
			auto hi = lower_bound(lo + 1 , primes.end(), n - *lo);
			if(*hi != (n - *lo)) --hi;
			
			count += (int)(hi - lo);
		} 
		printf("Case %d: %lld\n", ++tt, count);
	}
			
	return 0;
}
