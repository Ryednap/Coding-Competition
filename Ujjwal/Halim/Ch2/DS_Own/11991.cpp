#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, m;
	while( scanf("%d %d", &n, &m) != EOF ) {
		map<int, vector<int>> mapper;
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			mapper[x].push_back(i);
		}
		
		while (m -- ) {
			int k, v;
			scanf("%d %d", &k, &v);
			if(mapper.find(v) != mapper.end()) {
				--k;
				if(k < (int)mapper[v].size()) printf("%d\n", mapper[v][k] + 1);
				else puts("0");
			} else puts("0");
		}
	}
	return 0;
}
