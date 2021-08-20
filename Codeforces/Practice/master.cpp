#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std :: vector<int>;
using vvi = std :: vector <vi>;
using pii = std :: pair<int, int>;
using vpi = std :: vector<pii>;

#define f first
#define s second

int main () {
	int qq;
	scanf ("%d", &qq);
	
	using ll = long long;
	using vl = std :: vector<long long>;
	vl v;
	for (int i = 0; i < 60; ++i) {
		v.push_back(1ll << i);
	}

	for (int tt = 0; tt < qq; ++tt) {
		int n;
		scanf ("%d", &n);
		int ans = (int)1e9;

		auto calc = [&] (ll a, ll b) -> int {
			std :: string s = to_string(a);
			std :: string t = to_string(b);
			int j = 0;
			for (int i = 0; i < (int) s.length() && j < (int) t.length(); ++i) {
				if (s[i] == t[j])
					++j;
			}
			return std :: max ((int) s.length() - j, 0) + std :: max((int) t.length() - j, 0);
		};

		for (ll x : v) {
			ans = std :: min (ans, calc(n, x));
		}
		printf ("%d\n", ans);
	}
	return 0;
}
