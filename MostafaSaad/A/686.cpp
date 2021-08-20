#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	long long n, x;
	scanf("%lld %lld", &n, &x);
	int count = 0;
	for (int i = 0; i < n; ++i) {
		string op;
		int d;
		cin >> op >> d;
		if(op == "+") x += d;
		if(op == "-") {
			if(x < d) ++count;
			else x -= d;
		}
	}
	printf("%lld %d\n", x, count);
	return 0;
}