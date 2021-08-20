#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;

void Solve() {
	int n;
	scanf("%d", &n);
	vector<vi> A(n, vi(n)), B(n, vi(n));
	int R[n], C[n];
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			scanf("%d", &A[i][j]);
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &B[i][j]);
		}
	}
	
	for(int i = 0 ; i < n; ++i) {
		scanf("%d", &R[i]);
	}
	
	for(int i = 0 ; i < n; ++i) {
		scanf("%d", &C[i]);
	}
	
	int Num[n][n];
	int curr = 0;
	for(int i = 0; i < n; ++ i) {
		for(int j =0; j < n; ++j) {
			Num[i][j] = curr++;
		}
	}
	
	int answer = (int)1e9;
	for(int i = 0; i < (1 << (n * n)); ++i) {
			vector<vi> temp = A;
			int cost = 0;
			for(int l = 0; l < n; ++l) {
				for(int m = 0; m < n; ++m) {
					if(i & (1 << Num[l][m])) {
						cost += B[l][m];
						temp[l][m] = 0;
					}
				}
			}
			//if(cost == 7) debug() << owo("Before") owo(temp) owo(cost);
			bool here = true;
			while (here) {
				here = false;
				vi row(n);
				vi col(n);
				
				for(int l = 0; l < n; ++l) {
					for(int m = 0; m < n; ++m) {
						row[l] += (temp[l][m] == -1);
						col[m] += (temp[l][m] == -1);
					}
				}

				for(int l = 0; l < n; ++l) {
					for(int m = 0; m < n; ++m) {
						if(temp[l][m] == -1 && (row[l] <= 1 || col[m] <= 1)) {
							temp[l][m] = 0;
							here = true;
						}
					}
				} 
			}
			bool ok = true;
			for(int l = 0; l < n; ++l) {
				for(int m = 0; m < n; ++m) {
					if(temp[l][m] == -1) {
						ok = false;
					}
				}
			}
			
			if(ok) {
				//debug() << owo("ans") owo(temp);
				answer = min(answer, cost);
			}
		}
	printf("%d\n", answer);
			
	
}


int main() {
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i) {
		printf("Case #%d: ", i + 1);
		Solve();
	}
	return 0;
}
