#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(61 ^ 3) per test case with pruning of course

int main() {
	int n;
	// Precomputation
	set<int> score;
	for(int i = 0; i <= 20; ++i) {
		score.insert(i);
		score.insert(2 * i);
		score.insert(3 * i);
	}
	score.insert(50);
	
	// Start
	while (scanf("%d", &n) && n > 0) {
		
		int comb = 0, perm = 0;
		map<vector<int>, bool> used;
		
		for(int a : score) {
			if(a > n) break;
			for(int b : score) {
				if(a + b > n) break;
				for(int c : score) {
					if(a + b + c == n) {
						vector<int> v = {a, b, c};
						sort(v.begin(), v.end());
						if(!used[v]) {
							used[v] = true;
							++comb;
						} 
						++perm;
					} else if (a + b + c > n) break;
				}
			}
		}
		if(comb){
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n, comb);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,  perm);
		} else {
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		}
		puts("**********************************************************************");
	}
	puts("END OF OUTPUT");
	return 0;
}
