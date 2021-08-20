#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int OO = (int)1e9;
using pii = pair<int, int>;

/* IDEA

This problem is based on nested dp style. Consider this
	1 2 3 4 5 6
so now when we start with this we can start with any element and the we partition it into two part
left and right. Left part if 3 is sour and right part is 3 is bitter as we can have both the possibility. Also for the case that 
the choosen number itself is sweet is there as it stands alone
	 (1 2) 3 (4 5 6) suppose 3 is chosen

Now in the solution I have used pair to represent the length that is (2 + 1 + 3) * 3, but note that we don't need pair as this
is precisely the current length of the sequence.
*/

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while (qq--) {
		int n, k;
		scanf("%d %d", &n, &k);
		vector<vector<pii>> dp (n + 1, vector<pii> (n + 1, {-1, -1}));
		
		// {#compare, cost}
		function < pii (int, int) > Brute = [&] (int i, int j) {
			if(i > j) return make_pair(0, 0);
			if(i == j) return make_pair(1, 0);
			
			pii & ans = dp[i][j];
			if(ans.f != -1) return ans;
			
			ans = make_pair(OO, OO);
			for(int r = i; r < j; ++r) {
				pii a = Brute(i, r - 1);
				pii b = Brute(r + 1, j);
				int cost = a.s + b.s + (a.f + b.f + 1) * (r + k);
				if(ans.s > cost) {
					ans.s = cost;
					ans.f = a.f + b.f + 1;
				}
			}
			return ans;
		};
		pii answer = Brute(1, n);
		//debug() << owo(answer);
		printf("Case %d: %d\n",++tt,  answer.s);
	}
	
	return 0;
}
