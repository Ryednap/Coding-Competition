#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define mp(a, x) make_pair(a, x);
#define sz(x) ((int)x.size())

int main () {
	int a, b;
	scanf ("%d %d", &a, &b);
	int ans = 0;
	for (int i = 0; i < 1000; ++i) {
		if ((a ^ i) == b)
			ans = i;
	}
	printf ("%d\n", ans);
	return 0;
}