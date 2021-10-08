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
constexpr int OO = (int)1e9;

bool bellmanFord (const int n, const vector<pii> & adj, const vector<int> & cost, vector<int> & d) {
	int last;
	bool ok = true;
	for (int v = 0; v < n - 1; ++v) {
		last = -1;
		for (auto & edge : adj) {
			int from = edge.first;
			int to = edge.second;
			if (d[from] < OO) {
				int c;
				assert (to < (int)cost.size());
				if (from == 0 && ok) c = -100 + cost[to], ok = false;
				else c = d[from] + cost[to];
				if ((to == n - 1 || c < 0) && c < d[to]) d[to] = c, last = to;
			}
		}
	}
	return last != -1;
}

int main () {
	int n;
	while (scanf ("%d", &n) && n != -1) {
		vector<pii> edges;
		vector<int> energy(n);
		for (int i = 0; i < n; ++i) {
			int m; scanf ("%d %d", &energy[i], &m);
			energy[i] *= -1;
			for (int j = 0; j < m; ++j) {
				int b; scanf ("%d", &b);
				--b;
				edges.emplace_back(pii(i, b));
			}
		}
		vector<int> d(n, OO);
		d[0] = 0;
		bool cycle = bellmanFord(n, edges, energy, d);
		debug() << owo(cycle) owo(d);
		if (d[n - 1] < OO) puts ("winnable");
		else puts ("hopeless");
	}
}