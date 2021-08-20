#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int nax = 19;
int n, m;
vector<int> X(101), Y(101), Z(101);
long long dp[nax][1 << nax];

long long Brute(int i, int j) {
	
	//debug() << owo(i) owo(j);
	for(int k = 0; k < m; ++k) {
		int x = X[k], y = Y[k], z = Z[k];
		if(i > x) continue;
		
		for(int l = 1; l <= n; ++l) {
			if((j & (1 << l)) && l <= y)
				--z; 
		}
		if(z < 0) return 0;
	}
	
	
	if(i == n) {
		assert(__builtin_popcountll(j) == n);
		return 1;
	}

	long long & ans = dp[i][j];
	if(ans != -1) return ans;
	
	ans = 0;
	for(int k = 1; k <= n; ++k) {
		if(!(j & (1 << k))) {
			ans += Brute(i + 1, j | (1 << k));
		}
	}
	return ans;
}


int main() {
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; ++i) { 
		scanf("%d %d %d", &X[i], &Y[i], &Z[i]);
	}
	
	memset(dp, -1, sizeof(dp));
	long long answer = Brute(0, 0);
	printf("%lld\n", answer);
	
	return 0;
}
