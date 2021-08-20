#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n; scanf("%d", &n);
		long long sum = 0;
		for(int i = 0; i < n; ++i) {
			 int x; scanf("%d", &x);
			 sum += x;
		}

		long long q = sum / n;
		int r = sum % n;
		printf("%d\n", (n - r) * r);
	}
	return 0;
}