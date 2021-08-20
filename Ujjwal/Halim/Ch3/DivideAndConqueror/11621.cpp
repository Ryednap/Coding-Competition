#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const long long nax = 1LL << 31;

int main() {
	vector<long long> v;
	for(int i = 0; i <= 31; ++i) {
		for(int j = 0; j < 20; ++j) {
			long long x = (1LL << i) * (pow(3, j));
			if(x <= nax) {
				v.push_back(x);
			}
		}
	}
	
	sort(v.begin(), v.end());
	long long m;
	while (scanf("%lld", &m) && m) {
		auto itr = lower_bound(v.begin(), v.end(), m);
		assert(itr != v.end());
		printf("%lld\n", *itr);
	}
	return 0;
}
