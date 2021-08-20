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
	 std::sort(v.rbegin(), v.rend());
	 std::unordered_set<int> done;

	 ll ans = 0, curr = 1, rem = n;
	 for (int i = 0; i < m; ++i) {
	 	assert (v[i].s != 0);
	 	if (done.find(v[i].s) != done.end())
	 		continue;
	 	if (curr > n)
	 		break;
	 	curr = lcm (curr, v[i].s);
	 	done.insert (v[i].s);
	 	ans += 1ll * (rem - n / curr) * v[i].f;
	 	rem = n / curr;
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