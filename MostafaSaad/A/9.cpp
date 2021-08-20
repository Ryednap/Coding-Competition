#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int gcd (int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	int a = 6 - max(x, y) + 1;
	int b = 6;
	int d = gcd(a, b);
	a /= d;
	b /= d;
	printf("%d/%d", a, b);
	return 0;
}