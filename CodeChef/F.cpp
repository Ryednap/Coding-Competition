#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std :: vector<int>;
using vvi = std :: vector<vi>;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		vvi Edges(N);
		for(int i = 0; i < N - 1; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			--a; --b;
			Edges[a].push_back(b);
			Edges[b].push_back(a);
		}

		int timer = 0, lim = ceil(log2(N));
		vi tin(N), tout(N), depth(N, 0);
		vvi up(N, vi(lim + 2));


		function < void(int, int, int)> dfs = [&] (int node, int par, int d) {
			tin[node] = ++timer;
			depth[node] = d;
			up[node][0] = par;
			for(int i = 1; i <= lim; ++i) {
				assert(i < (int)up[node].size());
				up[node][i] = up[up[node][i - 1]][i - 1];
			}

			for(int child : Edges[node]) {
				if(child != par) dfs(child, node, d + 1);
			}
			tout[node] = ++timer;
		};

		auto isAncestor = [&] (int a, int b) {
			return tin[a] <= tin[b] && tout[a] >= tout[b];
		};

		auto lca = [&] (int a, int b) {
			if (isAncestor(a, b)) return a;
			if (isAncestor(b, a)) return b;
			for(int i = lim; i >= 0; --i) {
				if(!isAncestor(up[a][i], b)) a = up[a][i];
			}

			return up[a][0];
		};
		auto Dist = [&] (int a, int b) {
			int ancestor = lca(a, b);
			int res = depth[a] - depth[ancestor] + depth[b] - depth[ancestor];
			//debug() << owo(a + 1) owo(b + 1) owo(ancestor + 1) owo(res);
			return res;
		};


		dfs(0, 0, 0);
		int qq;
		scanf("%d", &qq);
		while (qq--) {
			int K;
			scanf("%d", &K);
			vi arr(K);
			for(int i = 0; i < K; ++i) {
				scanf("%d", &arr[i]);
				--arr[i];
			}

			if(K == 1) {
				puts("YES");
				continue;
			}

			sort(arr.begin(), arr.end(), [&](int a, int b) {
				return depth[a] > depth[b];
			});

			//debug() << owo(arr);

			int a = arr[0], b = arr[0], maxi = 0;
			for(int i = 1; i < K; ++i) {
				 if(Dist(a, arr[i]) > maxi) {
				 	maxi = Dist(a, arr[i]);
				 	b = arr[i];
				 }
			}

			//debug() << owo(a + 1) owo(b + 1);
			bool ok = true;
			for(int i = 0; i < K; ++i) {
				if(Dist(a, b) != Dist(a, arr[i]) + Dist(arr[i], b)) ok = false;
				//debug() << owo(a + 1) owo(arr[i] + 1) owo(b + 1);
				//debug() << owo(Dist(a, b)) owo(Dist(a, arr[i])) owo(Dist(arr[i], b));
			}
			
			puts(ok ? "YES" : "NO" );
		}
	}
	return 0;
}