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
const int OO = (int)1e9 + 10;
int main () {
	int tt;
	scanf ("%d", &tt);
	while (tt--) {
		int n, m, s, t, p;
		scanf ("%d %d %d %d %d", &n, &m, &s, &t, &p);
		vector<vector<pii>> edges(n), redges(n);
		vector<pair<int, pii>> edgeList(m);
		for (int i = 0; i < m; ++i) {
			 int a, b, w;
			 scanf ("%d %d %d", &a, &b, &w);
			 --a, --b;
			 edges[a].emplace_back(b, w);
			 redges[b].emplace_back(a, w);
			 edgeList[i] = make_pair(w, pii(a, b));
		}
		--s, --t;
		auto dijkstra = [&] (int src, vector<vector<pii>> & adjList) -> vector<int> {
			vector<int> dist(n, OO);
			dist[src] = 0;
			priority_queue<pii, vector<pii>, greater<pii>> pq;
			pq.push(pii(0, src));
			while (!pq.empty()) {
				auto node = pq.top(); pq.pop();
				if (dist[node.second] < node.first) continue;
				for (pii child : adjList[node.second]) {
					int cost = child.second + node.first;
					if (cost < dist[child.first]) {
						dist[child.first] = cost;
						pq.push(make_pair(cost, child.first));
					}
				}
			}
			return dist;
		};
		vector<int> from_start = dijkstra(s, edges);
		vector<int> from_end = dijkstra(t, redges);
		sort(edgeList.rbegin(), edgeList.rend());

		int ans = -1;
		for (auto & edge : edgeList) {
			int weight = edge.first;
			pii node = edge.second;
			if (from_start[node.first] + from_end[node.second] + weight <= p) {
				ans = weight;
				break;
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}