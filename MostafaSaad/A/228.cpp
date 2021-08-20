#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	set<int> s = {a, b, c, d};
	printf("%d\n", 4 - (int)s.size());
	return 0;
}