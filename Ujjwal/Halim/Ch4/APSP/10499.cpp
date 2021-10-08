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
using piii = pair<long long, pii>;
constexpr int OO = (int)1e9 + 10;

void bellmanFord (const int n, const vector<piii> & adj, vector<long long> & d) {
	d[0] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (auto edge : adj) {
			int w = edge.first;
			auto u = edge.second;
			if (d[u.first] < OO && d[u.first] + w < d[u.second]) {
				d[u.second] = d[u.first] + w;
			}
		}
	}
	for (auto edge : adj) {
		int w = edge.first;
		auto u = edge.second;
		if (d[u.first] < OO && d[u.first] + w < d[u.second]) d[u.first] = d[u.second] = -OO;
	}
}  


int main () {
	int n, tt = 0;
	while (scanf ("%d", &n) != EOF) {
		printf ("Set #%d\n", ++tt);
		vector<int> d(n + 1);
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		int m; cin >> m;
		vector<piii> edges;
		while (m--) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			edges.emplace_back(pow(1ll * d[b] - d[a], 3), pii(a, b));
		}	

		vector<long long> dist (n + 1, OO);
		bellmanFord (n, edges, dist);
		int qq; scanf("%d", &qq);
		while (qq--) {
			int node;
			scanf ("%d", &node);
			if (dist[node - 1] < 3 || dist[node - 1] == OO) puts ("?");
			else printf ("%lld\n", dist[node - 1]);
		}
	}	

	return 0;
}
