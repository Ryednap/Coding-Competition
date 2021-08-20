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

		vi parent(N, -1);
		int dest = -1;
		function < void (int, int) > dfs = [&] (int node, int par) {
			parent[node] = par;
			for(auto child : Edges[node]) {
				if(child != par) {
					dfs(child, node);
				}
			} 
		};

		int qq;
		scanf("%d", &qq);
		while (qq--) {
			int K; scanf("%d", &K);
			int arr[K];
			map<int, bool> mapper;
			for(int i = 0; i < K; ++i) {
				scanf("%d", &arr[i]);
				--arr[i];
				mapper[arr[i]] = true;
			}
			if(K == 1) {
				puts("YES");
				continue;
			}
			bool ok = false;
			for(int i = 0; i < K;  ++i) {
				for(int j = i + 1; j < K; ++j) {
					parent = vi(N, -1);
					dest = arr[j];
					dfs(arr[i], -1);
					int count = 0;
					while (dest != -1) {
						if(mapper[dest]) ++count;
						dest = parent[dest];
					}
					if(count == K) {
						ok = true;
						break;
					}
				}
				if(ok) break;
			}
			puts(ok ? "YES" : "NO");
		}
	}
		
	return 0;
}