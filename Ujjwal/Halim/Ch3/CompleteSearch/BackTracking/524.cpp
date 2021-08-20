#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// A very nice problem
// My first approach took time limit so i thought to reduce the complexity by symmetry, but that was ignoring few cases
// Finaly i figured that time limit for the complete search was due to the bug in the program, and that solved the problem but after like 
// half an hour. :<

// It's hard for me to debug the backtracking problem. Really hardl
	
bool primeCheck (int x) {
	if(x == 2 || x == 3) return true;
	if(x % 2 == 0 || x % 3 == 0) return false;
	
	for(int i = 5; i <= sqrt(x); i += 2) {
		if(x % i == 0) return false;
	}
	return true;
}

int prime[35];
int main() {
	for(int i = 2; i < 35; ++i) {
		prime[i] = primeCheck(i);
	}
	int n, tt = 0;
	scanf("%d", &n);
	while (true) {

		int ans[n + 1];
		function < void(int, int) > Solve = [&] (int x, int y) {
			if(y == n) {
				if(!prime[ans[0] + ans[n - 1]]) return;
				printf("%d", ans[0]);
				for(int i = 1; i < n; ++i) {
					printf(" %d", ans[i]);
				}
				puts("");
			}
	
			for(int i = 2; i <= n; ++i) {
			
				if(!(x & (1 << i)) && prime[i + ans[y - 1]]) {

					ans[y] = i;
					Solve(x | (1 << i), y + 1);
				}
			}
		};
		printf("Case %d:\n", ++tt);
		ans[0] = 1;
		Solve(2, 1);
		if(scanf("%d", &n) != EOF) puts("");
		else break;
	}
	return 0;
}
