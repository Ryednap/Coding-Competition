#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

/*
 * If we think more closely we may see that the problem already represents a dp but is more kind a Brute force so if we model it into a dp then 
 * we know that state diagram is a tree so think like the sum of all nodes in the state diagram, 
 * 
 * NOTE :- C++ version needs additional Big Integer Library refer the java file. 
 */


const int nax = 70;
int n, back;
long long dp[nax];

long long Brute(int i) {
	if(i <= 1) return 1;
	
	long long & ans = dp[i];
	if(ans != -1) return ans + 1;
	ans = 0;
	for(int j = 1; j <= back; ++j) {
		ans += Brute(i - j);
	}
	return ans + 1;
}

int main() {
	int tt = 0;
	while (scanf("%d %d", &n, &back) && n < 61) {
		memset(dp, -1, sizeof(dp));
		printf("Case %d: %lld\n", ++tt, Brute(n));
	}
	
	return 0;
}
