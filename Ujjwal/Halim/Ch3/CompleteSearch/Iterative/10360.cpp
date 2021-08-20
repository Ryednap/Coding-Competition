#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A very nice problem on rethinking about problem search domain


int main() {
	int qq;
	scanf("%d", &qq);
	while( qq--) {
		int d, n;
		scanf("%d %d", &d, &n);
		int mat[1025][1025] = {0};
		for(int _ = 0; _ < n; ++_) {
			int x, y, p;
			scanf("%d %d %d", &x, &y, &p);
			--x, --y;
			for(int i = x - d; i <= x + d; ++i) {
				for(int j = y - d; j <= y + d; ++j) {
					if(i < 0 || j < 0 || i >= 1025 || j >= 1025) continue;
					if(max(abs(i - x), abs(y - j)) <= d) {
						mat[i][j] += p;
					}
				}
			}
		}
		int ans_x = 0, ans_y = 0, ans = 0;
		for(int i = 0; i < 1025; ++i) {
			for(int j = 0; j < 1025; ++j) {
				if(mat[i][j] > ans) {
					ans = mat[i][j];
					ans_x = i, ans_y = j;
				}
			}
		}
		printf("%d %d %d\n", ans_x + 1, ans_y + 1, ans);
	}
	return 0;
}
