#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
#define f first
#define s second




int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) { 
		int a, b;
		scanf("%d %d", &a, &b);
		debug() << owo(__gcd(a, b));
		if(__gcd(a, b) != 1)
			puts("0");
		else if(__gcd(a + 1, b) != 1 || __gcd(a, b + 1) != 1)
			puts("1");
		else puts("2");
	}
	return 0;
}