#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(50 * 50 * 50 * q) per test case

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, m, q;
		scanf("%d %d %d", &n, &m, &q);
		string mat[n];
		for(int i = 0; i < n; ++i) {
			cin >> mat[i];
		}
		
		printf("%d %d %d\n", n, m, q);
		for(int _ = 0; _ < q; ++_) {
			int r, c;
			scanf("%d %d", &r, &c);

			
			int ans = 0;
			for(int side  = 0; side <= 100; side += 2) {
				bool ok = true;
				int a = side >> 1;
				set<char> s;
				for(int i = r - a; i <= r + a && ok; ++i) {
					for(int j = c - a; j <= c + a && ok ; ++j) {
						if(i < 0 || j < 0 || i >= n || j >= m) ok = false;
						else s.insert(mat[i][j]);
					}
				}
				if(!ok) break;
				if((int)s.size() == 1) ans = max(ans, side + 1 ); // Missed here for checking ok
			}
			assert(ans != 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}
