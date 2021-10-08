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


int main () {
	ios::sync_with_stdio(false);
	int qq; cin >> qq;
	while (qq--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		vector<vector<int>> edges(n);
		for (int & x : a) cin >> x;
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			-- u,  --v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		vector<int> store(n), depth(n);
		function < int (int, int, int) > dfs = [&] (int v, int p, int d = 0) {
			int ans = a[v];
			depth[v] = d;
			for (int u : edges[v]) {
				if (u != p) ans ^= dfs(u, v,d  + 1);
			}
			return store[v] = ans;
		};
		int x = dfs(0, -1, 0);
		debug() << owo(x);
		if (x == 0) cout << "Yes" << "\n";
		else if (k - 1 < 2) cout << "No" << "\n";
		else {
			int curr_depth = -1, start = 0;
			pair<int, int> curr_value = {-1, -1};
			function < void (int, int) > dfs2 = [&] (int v, int p) {
				if (store[v] == x && v != start) {
					if (depth[v] > curr_depth) {
						curr_depth = depth[v];
						curr_value = make_pair(p, v);
					}
				}

				for (int u : edges[v]) {
					if (u != p) dfs2(u, v);
				}
			};
			dfs2(0, -1);
			if (curr_value.first == -1) cout << "No" << "\n";
			else {
				dfs(curr_value.first, curr_value.second, 0);
				auto t_value = curr_value;
				curr_depth = -1, curr_value = {-1, -1};
				start = t_value.first;
				dfs2(t_value.first, t_value.second);
				if (curr_value.first == -1) cout << "No" << "\n";
				else cout << "Yes" << "\n";
			}
		}
	}
	return 0;
}