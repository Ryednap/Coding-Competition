#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int> ;
// Mistakes 

/*
 * The problem is easy : 
 * First should have paid attention to non-trivial size. It's not affordable in matrix so an adjacency list is recommended.
 * Second lot's of debugging should have put asserts.
 * 
 */
int main() {
	int n, m;
	while( scanf("%d%d",&n, &m) != EOF ) {
		vector<int> a[m + 1], b[m  + 1];
		for(int i = 0; i < n; ++i) {
			int r; scanf("%d", &r);
			if(!r) continue;
			int R[r];
			for(int j = 0; j < r; ++j) {
				scanf("%d", &R[j]);
				R[j]--;
			}
			for(int j = 0; j < r; ++j) {
				int x ; scanf("%d",&x);
				a[R[j]].push_back(x);
				b[R[j]].push_back(i);
			}
		}

		//vector<vi> ans(m, vi(n));
		//for(int i = 0; i < n; ++i) {
			//for(int j = 0; j < m; ++j) {
				//ans[j][i] = mat[i][j];
			//}
		//}
		
		printf("%d %d\n", m, n);
		
		
		for(int i = 0; i< m; ++i) {
			const int r = (int)a[i].size();
			printf("%d", r);
			for(int j = 0; j < r; ++j) {
				printf(" %d", b[i][j] + 1);
			}
			puts("");
			if(r) {
				printf("%d", a[i][0]);
				for(int j = 1; j < r;  ++j) {
					printf(" %d", a[i][j]);
				}
			}
			puts("");
		}
		//for(int i = 0; i < m; ++i) {
			//vi a, b;
			//for(int j = 0; j < n; ++j) {
				//if(ans[i][j] != 0) a.push_back(j), b.push_back(ans[i][j]);
			//}
			//const int r = (int)a.size();
			//printf("%d", r);
			//for(int j = 0; j < r; ++j) {
				//printf(" %d", a[j] + 1);
			//}
			//puts("");
			//if(r) {
				//printf("%d", b[0]);
				//for(int j = 1; j < r; ++j) {
					//printf(" %d", b[j]);
				//}
			//}
			//puts("");
		//}
	}
	return 0;	
}
