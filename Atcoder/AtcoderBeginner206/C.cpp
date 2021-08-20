#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

long long nC2(int n) {
	return ((long long)n * (n - 1)) >> 1;
}

int main() {
	int n;
	scanf("%d", &n);
	map<int, int> mapper;
	for( int i = 0; i < n; ++ i ) {
		int x; 
		scanf("%d", &x);
		mapper[x]++;
	}

	long long total = nC2(n);
	for(auto & p : mapper) {
		total -= nC2(p.second);
	}
	printf("%lld\n", total);
	return 0;
}