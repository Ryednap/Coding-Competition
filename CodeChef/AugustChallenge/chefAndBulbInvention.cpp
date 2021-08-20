#include <bits/stdc++.h>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)


void solve() {
	int n, p, k;
	scanf ("%d %d %d", &n, &p, &k);
	int modP = p % k;
	int ans = (n + k - 1) / k * modP;
	ans += (p / k);
	printf ("%d\n", ans + 1);
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		solve();
	}
	return 0;
}