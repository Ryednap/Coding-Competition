#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int n, m, tt = 0;
	while (scanf("%d %d", &n, &m)) {
		if(!n && !m) break;
		
		int mini = (int)1e9;;
		for(int i = 0; i < n;  ++i) {
			int x; scanf("%d", &x);
			mini = min(mini, x);
		}
		for(int j = 0; j < m; ++j) {
			int x; scanf("%d", &x);
		}
		
		printf("Case %d: ", ++tt);
		if(n > m) printf("%d %d\n", n - m , mini);
		else printf("%d\n", 0);
	} 
	return 0;
}
