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
	Level 6 problem
	The problem asks us to find largest distance
	we can reverse the weight value and find the SSSP that's all.
*/

using pii = pair<int, int>;
using piii = pair<int, pii>;

const int OO = (int)1e9;
bool bellmanFord (int n, const vector<piii> & adj, vector<int> & d) {
	int last;
	for (int i = 0; i < n; ++i) {
		last = -1;
		for (auto & edges : adj) {
			int w = edges.first;
			auto p = edges.second;
			if (d[p.first] < OO && d[p.second] > d[p.first] + w) {
				d[p.second] = d[p.first] + w;
				last = p.second;
			}
		}
	}
	debug() << owo(last) owo(d) owo(adj);
	return (last == -1);
}

int main () {
	int n, m;
	while (scanf ("%d %d", &n, &m)) {
		if (!n && !m) break;
		vector<piii> edges(m);
		for (auto & p : edges) {
			scanf ("%d %d %d", & p.second.first, &p.second.second,&p.first);
			--p.second.second;
			--p.second.first;
			p.first *= -1;
		}
		vector<int> dist(n, OO);
		dist[0] = 0;
		bool ok = bellmanFord(n, edges, dist);
		if (!ok) puts("Unlimited!");
		else printf ("%d\n", -1 * *min_element(dist.begin(), dist.end()));
	}
	return 0;
}