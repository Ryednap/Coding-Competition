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
    int n, m, b, p;
    while (scanf ("%d %d %d %d", &n, &m, &b, &p) != EOF) {
        vector<vector<pii>> edges(n);
        for (int i = 0 ; i < m; ++i) {
            int u, v, w;
            scanf ("%d %d %d", &u, &v, &w);
            edges[u].emplace_back(v, w);
            edges[v].emplace_back(u, w);
        }
        set<int> banks;
        for (int i = 0; i < b; ++i) {
        	int x; scanf ("%d", &x);
        	banks.insert(x);
        }

        auto dijkstra = [&] ( )-> vector<int> {
        	vector<int> dist(n, (int)1e9);
        	priority_queue<pii, vector<pii>, greater<pii>> pq;
        	for (int i = 0; i < p; ++i) {
        		int x; scanf ("%d", &x);
        		dist[x] = 0;
        		pq.push(pii(0, x));
        	}

        	while (!pq.empty()) {
        		auto v = pq.top(); pq.pop();
        		int w = v.first, node = v.second;
        		if (w > dist[node]) continue;
        		for (pii & c : edges[node]) {
        			int cost = w + c.second;
        			if (cost < dist[c.first]) {
        				dist[c.first] = cost;
        				pq.push(make_pair(cost, c.first));
        			}
        		}
        	}
        	return dist;
        };

     	auto ans = dijkstra();
    	int value = 0, num = 0;
    	for (int i = 0; i < n; ++i) {
    		if (banks.find(i) != banks.end()) value = max(value, ans[i]);
    	}
    	vector<int> store;
    	for (int i = 0; i < n; ++i) {
    		if (banks.find(i) != banks.end() && ans[i] == value) ++num, store.push_back(i);
    	}
   		printf("%d ", num);
   		if (value >= (int)1e9) puts("*");
   		else printf ("%d\n", value);
   		if (!store.empty()) printf ("%d", store[0]);
   		for (int i = 1; i < (int)store.size(); ++i) printf (" %d", store[i]);
   		puts("");
    }
    return 0;
}