#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int curr = 0;
	for(int i = 0; i < n; ++i) {
		printf("%c", (char)('a' + curr));
		curr = (curr + 1) % k;
	}
	puts("");
	return 0;
}