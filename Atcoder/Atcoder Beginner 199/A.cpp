#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second



int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	puts(a * a + b * b < c * c ? "Yes" : "No");		
	return 0;
}
