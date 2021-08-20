#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main() {
	string graph, get;
	while (getline(cin, graph) && graph != "#") {
		stringstream ss(graph);
		map<char, int> mapper;
		
		int mat[8][8] = {0}, idx = 0;
		vector<char> ar;
		
		while (getline(ss, get, ';')) {
			char src = get[0];
			
			if(mapper.find(src) == mapper.end()) {
				mapper[src] = idx++;
				ar.push_back(src);
			}
			
			for(int i = 2; i < (int)get.length(); ++i) {
				char to = get[i];
				if(mapper.find(to) == mapper.end()) {
					mapper[to] = idx++;
					ar.push_back(to);
				}
				int a = mapper[src], b = mapper[to];
				mat[a][b] = mat[b][a] = 1;
			}
		}
		
		sort(ar.begin(), ar.end());
		pair<vector<char>, int> ans = {{}, (int)1e9};
		
		do {
			
			int cost = 0;
			for(int i = 0; i < idx; ++i) {
				for(int j = 0; j < idx; ++j) {
					if(mat[i][j]) {
						int a = -1, b = -1;
						for(int k = 0; k < idx; ++k) {
							if(mapper[ar[k]] == i) a = k;
							if(mapper[ar[k]] == j) b = k;
						}
						assert(a != -1 && b != -1);
						cost = max(cost, abs(b - a));
					}
				}
			}
			if(ans.s > cost) {
				ans.s = cost, ans.f = ar;
			} else if(ans.s == cost) {
				ans.f = min(ans.f, ar);
			}
			
		} while (next_permutation(ar.begin(), ar.end()));
		
		for(int i = 0; i < idx; ++i) {
			printf("%c ", ans.f[i]);
		}
		printf("-> %d\n", ans.s);

	}
		
	return 0;
}
