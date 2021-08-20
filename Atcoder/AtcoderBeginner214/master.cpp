#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using vpi = std::vector<pii>;
using vvpi = std::vector<vpi>;


#define f first
#define s second
#define len length()

const int nax = 110;

int main () {
	int n;
	scanf ("%d", &n);
	vi arr(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf ("%d %d %d", &a, &b, &c);
		arr[i] = c;
	}

	sort (arr.rbegin(), arr.rend());
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += 1ll * arr[i - 1] * (n - i);
	}
	printf ("%lld\n", ans);
	return 0;
}