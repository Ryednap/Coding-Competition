#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif



int main() {
	int n, x;
	scanf("%d %d",&n, &x);
	x *= 100;
	
	long total = 0;
	for(int i = 0;i < n; ++i) {
		int a, b;
		scanf("%d %d",&a, &b);
		total += (long)a * b;
		if(total > x) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
