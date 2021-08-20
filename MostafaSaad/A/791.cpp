#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int years = 0;
	while (a <= b) {
		++years;
		a = a * 3;
		b = b * 2;
	}
	printf("%d\n", years);
	return 0;
}


