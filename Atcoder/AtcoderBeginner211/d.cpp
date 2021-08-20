#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pii>;

#define f first
#define s second
const int mod = (int)1e9 + 7;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vi> Edges(n);
	for(int i = 0 ;i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		Edges[a].push_back(b);
		Edges[b].push_back(a);
	}

	queue<pii> q;
	q.push(pii(0, 0));
	vi path(n + 1, 0);
	vi used(n + 1, false);
	vi minCost(n + 1, (int)1e9);
	path[0] = 1;
	while (!q.empty()) {
		pii node = q.front(); q.pop();
		if(node.f == n - 1)
			break;
		used[node.f] = true;
		for(int child: Edges[node.f]) {
			if(!used[child]) {
				int costNext = node.s + 1;
				if(minCost[child] > costNext) {
					minCost[child] = costNext;
					path[child] = path[node.f];
					q.push({child, min(costNext, minCost[child])});

				} else if(minCost[child] == costNext) path[child] = Add(path[child],path[node.f]);
				
			}
		}
	}
	//debug() << owo(path);
	printf("%d\n", path[n - 1]);
		return 0;
}