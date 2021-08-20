#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n! * m) complexity

// Quite easy problem;

int main() {
	int n, m;
	while (scanf("%d %d", &n,&m)) {
		if(!n && !m) break;
		
		int ar [n];
		array<int, 3> group[m + 1];
		for(int i = 0; i < n; ++i) {
			ar[i] = i;
		}
		
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < 3; ++j) {
				scanf("%d", &group[i][j]);
			}
		}
		
		
		int answer = 0;	
		do {
			bool ok = true;
			map<int, int> position;
			for(int i = 1; i <= n; ++i) {
				position[ar[i - 1]] = i;
			}
			
			for(int i = 0; i < m; ++i) {
				int a = position[group[i][0]];
				int b = position[group[i][1]];
				int c = (group[i][2]);
				int d = abs(a - b);
				if(c > 0) {
					if(d > c) ok = false;
					
				} else {
					if(d < abs(c)) ok = false;
				}
				if(!ok) break;
			}
			
			answer += ok;
			
		} while (next_permutation(ar, ar + n));
		
		printf("%d\n", answer);
	}
		
	return 0;
}
