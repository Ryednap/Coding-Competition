#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*

T 000:19:51.105
T 000:04:09.294
T 000:01:56.248


*/


using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using piii = std::pair<int, pii>;

#define f first
#define s second


int main () {
	int n;
	while (scanf ("%d", &n) && n) {
		vector<pii> v(n);
		for (pii & p : v) {
			scanf ("%d %d", &p.f, &p.s);
		}

		vi used = vi(n);
		auto dist = [&] (int i, int j) {
			int x = (v[i].f - v[j].f);
			int y = (v[i].s - v[j].s);
			return x * x + y * y;
		};

		function < void (int) > dfs = [&] (int i) {
			used[i] = true;
			vector<pii> order;
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				if ((int) order.size() == 3) {
					order.pop_back();
				}
				order.emplace_back(dist(i, j), j);
				sort (order.begin(), order.end(), [&] (const pii & a, const pii & b){
					if (a.f == b.f) {
						if (v[a.s].f == v[b.s].f)
							return v[a.s].s < v[b.s].s;
						return v[a.s].f < v[b.s].f;
					}
					return a.f < b.f;
				});
			}
			for (int j = 0; j < min(2, (int)order.size()); ++j) {
				if (!used[order[j].s])
					dfs (order[j].s);
			}
		};
		dfs (0);
		if (find(used.begin(), used.end(), false) == used.end()) {
			puts ("All stations are reachable.");
		} else puts ("There are stations that are unreachable.");
	}
}