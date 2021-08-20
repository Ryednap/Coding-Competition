#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int NAX = 60;
// total bars  total grp , m, color
long long dp[NAX][NAX][NAX];
int n, p, m;

// dp[i][j][k] means that when the total length is i and j units have been used and currently k units of each bar has been used.

/*
 * You will find 3 WA first 2 are simultaneous and because there was a typo when submitting I pressed a wrong buttong and + 50 was written on line 32
 * Third WA due to changing previous but now I put a ; instead of +

 */
long long Brute(int i, int j, int k) {
	if(j > p || k > m) return 0;	
	//debug() << owo(i) owo(j) owo(k);
	if(i == n) return j == p;
	
	long long & ans = dp[i][j][k];
	if(ans != -1) return ans;
	
	return ans = Brute(i + 1, j , k + 1) + 
					Brute(i + 1, j + 1, 1);
}

	

int main() {
	while (scanf("%d %d %d", &n, &p, &m) != EOF) {
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", Brute(1, 1, 1));
	}
	
	return 0;
}
