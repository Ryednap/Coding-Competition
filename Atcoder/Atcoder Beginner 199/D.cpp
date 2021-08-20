#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> edges[n];
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
		
		

	}
	printf("%lld\n", answer);	
	return 0;
}
