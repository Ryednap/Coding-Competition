#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Nice cute problem
// O(n ^ 6) in the worst like algorithm

int main() {
	int n, m;
	while (scanf("%d", &n) && n) {
		scanf("%d", &m);
		string mat[n];
		for(int i = 0 ; i < n; ++i) {
			cin >> mat[i];
		}
		
		auto Check = [&] (int a, int b, int c, int d) {
			for(int i = a; i <= b; ++i) {
				for(int j = c; j <= d; ++j) {
					if(i >= n || j >= m) return false;
					if(mat[i][j] == '0') return false;
				}
			}
			return true;
		};
		
		int count = 0;
		for(int l = 0; l < n; ++l) {
			for(int b = 0; b < m; ++b) {
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < m; ++j) {
						bool ok = Check(i, i + l, j, j + b);
						if(ok) ++count;
					}
				}
			}
		}
		printf("%d\n", count);
	}
							
	return 0;
}
