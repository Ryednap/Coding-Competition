#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if(b > a) swap(a, b);
		if(a == b) {
			puts("0 0");
		} else {
			long long d = a - b;
			long long r = a % d;
			printf("%lld %lld\n", d, r);
		}
	}
	return 0;
}