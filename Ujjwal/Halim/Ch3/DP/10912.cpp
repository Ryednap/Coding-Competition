#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

// Time limit exceed in the first attempt

// Reason :- This problem like query wise
// So either solve it using table method
// If you want to use recurssive then start from back i.e from i = n and j = m else you will always get wrong answer.


/* IDEA 

	Note although L and S are given to be of the limit 10000 Note that the length can never be greater than 26 as you can no more
	satisfy the constraint of increasing alphabets. So this algorithm is pretty simple O(L * L * S) which will pass the time limit.

*/

using vi = vector<int>;
const int nax = (int)1e4 + 42;

int main() {
	int n, m;
	int tt = 0;
	vector<vector<vi>> dp(27, vector<vi> (nax, vi(27, -1)));
	while (scanf("%d %d",&n, &m) && n) {

		n = min(26, n);
		function < int (int, int, int) > Brute = [&] (int i, int j, int k) {
			if(j < 0) return 0;
			if(i == 0) return (j == 0 ? 1 : 0);
			if(k > 26) return 0;
			int & ans = dp[i][j][k];
			if(ans != -1) return ans;
			return ans = Brute(i, j, k + 1) + 
							Brute(i - 1, j - k, k + 1);
		};
		
		printf("Case %d: %d\n", ++tt, Brute(n, m, 1));
	}
				
	return 0;
}
