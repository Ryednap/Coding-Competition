#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Although it's pruned O(n ^ 3) But still in complete graph i can't bet it should pass
// pruning is based on making the graph undirected as per the constraint a and b has edge only if a < b
// this does 2 things :- First, it relaxes graph. Second it prevents double or triple counting.

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> edges[n + 1];
		int mat[n + 1][n + 1] = {0};
		for(int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d",&a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
			mat[a][b] = mat[b][a] = 1;
		}
		
		for(int i = 1; i <= n; ++i) {
			sort(edges[i].begin(), edges[i].end());
			vector<int> temp;
			for(int x : edges[i]) {
				if(x > i) temp.push_back(x);
			}
			edges[i] = temp;
		}
		
		int answer = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j : edges[i]) {
				assert(j > i);
				for(int k : edges[j]) {
					if(k <= max(i, j)) continue;
					if(mat[k][i]) ++answer;
				}
			}
		}
		printf("%d\n", answer);
								
	}
	return 0;
}
