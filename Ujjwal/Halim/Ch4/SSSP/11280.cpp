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

/*
	Lvl 5.
	The problem comes under SSSP but can be easily solved with dp
	Note that the graph is always DAG

*/

using pii = pair<int, int>;
using piii = pair<int, pii>;

int main () {
	int tt ; scanf ("%d", &tt);
	for (int qq = 1; qq <= tt; ++qq) {
		printf ("Scenario #%d\n", qq);
		int n; scanf ("%d", &n);
		unordered_map<string, int> mapper;

		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			mapper[s] = i;
		}
		assert (mapper["Calgary"] == 0 && mapper["Fredericton"] == n - 1);

		int m; scanf ("%d", &m);
		vector<vector<pii>> edges(n);
		for (int i = 0; i < m; ++i) {
			string from, to;
			int w;
			cin >> from >> to;
			scanf ("%d", &w);
			int a = mapper[from], b = mapper[to];
			edges[a].emplace_back(b, w);
		}
		vector<int> dag, vis(n, false);

		function < void (int) > dfs = [&] (int node) {
			vis[node] = true;
			for (auto child : edges[node]) {
					if (!vis[child.first]) dfs (child.first);
			}
			dag.push_back(node);
		};
		dfs (0);
		reverse(dag.begin(), dag.end());
		debug () << owo(dag) owo(edges);

		const int OO = (int)1e9;
		vector<vector<int>> dp(n, vector<int> (n + 2, OO));
		dp[0][0] = 0;
		for (int node : dag) {
			for (auto p : edges[node]) {
				int i = p.first;
				int w = p.second;
				for (int j = 0; j < n + 1; ++j) {
					dp[i][j + 1] = min (dp[i][j + 1], dp[node][j] + w);
				}
			}
		}

		for (int i = 0; i < n + 1; ++i) {
			dp[n - 1][i + 1] = min (dp[n - 1][i + 1], dp[n - 1][i]);
		}

		int q; scanf ("%d", &q);
		while (q--) {
			int x ; scanf ("%d", &x);
			x = min (x + 1, n + 1);
			int value = dp[n - 1][x];
			if (value >= OO) puts ("No satisfactory flights");
			else printf ("Total cost of flight(s) is $%d\n", value);
		}
		if (qq != tt) puts("");
	}
}