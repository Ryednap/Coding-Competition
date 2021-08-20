
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int OO = (int)1e4;

// O(n^3) complexity
// O(n^2) is possible by precomputing the nearest 0 cell location.

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while (qq--) {
		int r, c;
		scanf("%d %d",&r, &c);
		string mat[r];
		for(int i = 0; i < r; ++i) {
			cin >> mat[i];
		}
		
		int answer = OO;
		for(int i = 0; i < c; ++i) {
			int cost = 0;
			for(int j = 0; j < r; ++j) {
				int left = i, right = i;
				while(mat[j][left] != '0') {
					--left;
					if(left < 0) {
						left = -OO;
						break;
					}
				}
				while (mat[j][right] != '0') {
					++right;
					if(right >= c) {
						right= OO;
						break;
					}
				}
				if(left == -OO && right == OO) { // mistake here initially left == OO
					cost += OO;
					break;
					
				} else cost += min(i - left, right - i);
			}
			answer = min(answer, cost);
		}	
		if(answer == OO) answer = -1;
		printf("Case %d: %d\n", ++tt, answer);
	}
	return 0;
}
