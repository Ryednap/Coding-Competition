#include <bits/stdc++.h>

using vi = std :: vector<int>;
using vvi = std :: vector<vi>;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, qq;
		scanf("%d %d", &N, &qq);
		vvi Edges(N);
		for(int i = 0; i < N - 1; ++i) {
			int a, b; 
			scanf("%d %d", &a, &b);
			--a, --b;
			Edges[a].push_back(b);
			Edges[b].push_back(a);
		}

		int timer = 0, lim = ceil(log2(N));
		vi tin(N), tout(N), depth(N);
		vvi up(N, vi (32));

		std :: function < void(int, int, int) > dfs = [&] (int node, int par, int d) {
			//printf("node %d %d\n", node, par);
			tin[node] = ++timer;
			depth[node] = d;
			up[node][0] = par;
			for(int i = 1; i <= lim; ++i) {
				assert(i < (int)up[node].size());
				up[node][i] = up[up[node][i - 1]][i - 1];
			}

			for(int child : Edges[node]) {
				if(child != par) {
					dfs(child, node, d + 1);
				}
			}
			tout[node] = ++timer;
		};

		auto isAncestor = [&] (int a, int b) {
			return tin[a] <= tin[b] && tout[a] >= tout[b];
		};

		auto lca = [&] (int a, int b) {
			if(isAncestor(a, b)) return a;
			if(isAncestor(b, a)) return b;

			for(int i = lim; i >= 0; --i) {
				if(!isAncestor(up[a][i], b)) a = up[a][i];
			}

			return up[a][0];
		};

		auto Dist = [&] (int a, int b) {
			int ancestor = lca(a, b);
			return depth[a] - depth[ancestor] + depth[b] - depth[ancestor];
		};

		dfs(0, 0, 0);

		while(qq--) {
			int K, D;
			scanf("%d %d", &K, &D);
			vi arr(K);
			for(int i = 0; i < K; ++i) {
				scanf("%d", &arr[i]);
				--arr[i];
			}

			int answer = 0;
			for(int i = 0; i < K; ++i) {
				for(int j = i + 1;j < K; ++j) {
				//	printf("node %d %d\n", arr[i], arr[j]);
					if(Dist(arr[i], arr[j]) == D) ++answer;
				}
			}
			printf("%d\n", answer);
		}
	}
}