#include <bits/stdc++.h>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)

ll lcm (ll a, ll b) {
	return (a * b) / std::__gcd(a, b);
}

void solve() {
	 int n, m;
	 scanf ("%d %d", &n, &m);	
	 std::vector<pii> v (m);
	 for (auto & p : v) {
	 	scanf ("%d %d", &p.f, &p.s);
	 }
	 std::sort (v.rbegin(), v.rend());
	 vi used(n + 1, 0);
	 ll ans = 0;
	 for (int i = 0; i < m; ++i) {
	 	for (int j = 1; j <= n; ++j) {
	 		assert (v[i].s != 0);
	 		if (used[j] || j % v[i].s == 0)
	 			continue;
	 		used[j] = true;
	 		ans += v[i].f;
	 	}
	 }
	 printf ("%lld\n", ans);
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		solve();
	}
	return 0;
}