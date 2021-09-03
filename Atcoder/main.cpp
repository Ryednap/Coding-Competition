#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

void fun (int n) {
	int ans = n;
	int prev = n & 1;
	n >>= 1;
	int i = 1;
	for ( i = 1; n; ++i, n >>= 1) {
		int curr = n & 1;
		debug() << owo(curr) owo(prev);
		if (curr != prev) {
			ans ^= (1 << i);
			ans ^= (1 << (i - 1));
		} else prev = curr;	
	}
	printf ("%d\n", ans);
}
int main () {
	int n;
	scanf ("%d", &n);
	fun(n);
	return 0;
}