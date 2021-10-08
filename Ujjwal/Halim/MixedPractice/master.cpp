#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
	sim > struct rge { c b, e; };
	sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
	sim > auto dud(c* x) -> decltype(cerr << *x, 0);
	sim > char dud(...);
	struct debug {
#ifdef LOCAL
		~debug() { cerr << endl; }
		eni(!=) cerr << boolalpha << i; ris; }
		eni(==) ris << range(begin(i), end(i)); }
		sim, class b dor(pair < b, c > d) {
			ris << "(" << d.first << ", " << d.second << ")";
		}
		sim dor(rge<c> d) {
			*this << "[";
			for (auto it = d.b; it != d.e; ++it)
				*this << ", " + 2 * (it == d.b) << *it;
			ris << "]";
		}
#else
		sim dor(const c&) { ris; }
#endif
	};
#define owo(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using pii = pair<int, int>;

int main () {
	int n, f;
	while (scanf ("%d %d", &n, &f) != EOF) {
		vector<vector<pii>> edges(n);
		for (int i = 0; i < n - 1; ++i) {
			 int a, b, c;
			 scanf ("%d %d %d", &a, &b, &c);
			 --a, --b;
			 edges[a].emplace_back(b, c);
			 edges[b].emplace_back(a, c);
		}

		vector<int> isTrue (n, false);
		for (int i = 0; i < f; ++i) {
			int x; scanf ("%d", &x);
			--x; isTrue[x] = true;
		}
		set<pair<int, pii>> s;
		vector<bool> has(n, false);
		function < bool (int, int) > dfs_util = [&] (int u, int p) {
			bool ok = false;
			for (auto c : edges[u]) {
				if (c.first != p) ok |= dfs_util (c.first, u);
			}
			return has[u] = ok | isTrue[u];
		};

		function < int (int, int) > dfs = [&] (int u, int p) {
			int d = 0;
			for (auto child : edges[u]) { 
				 int v = child.first;
				 int w = child.second;

				 if (v != p && has[v]) {
				 	d = max (dfs (v, u) + w, d);
				 	s.insert (make_pair(w, pii(u, v)));
				 }
			}
			return d;
		};

		dfs_util(0, -1);
		int maxi = dfs (0, -1);
		int ans = 0;
		for (auto & p : s) ans += p.first;
		printf ("%d\n", ans - maxi);
	}
	return 0;
}