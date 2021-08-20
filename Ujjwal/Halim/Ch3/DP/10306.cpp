#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
const int OO = (int)1e8;

// Took more time than usual because of two reasons

// 1. Couldn't understood the meaning of e-modulus clearly was taking sum of sqrt(x * x + y * y)
// 2. Misunderstanding in max state.

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, S;
		scanf("%d %d",&n, &S);
		
		
		vi X(n), Y(n);
		
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &X[i], &Y[i]);
		}
		
		vector<vi> dp(S + 10, vi(S + 10, -1));
		
		auto F = [&] (int i, int j) {
			return i * i + j * j;
		};
		
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(F(i, j) == S * S) return 0;
			if(F(i, j) > S * S) return OO;
			
			int & ans = dp[i][j];
			if(ans != -1) return ans;
			
			int a = OO;
			for(int k = 0; k < n; ++k) { 
				a = min(a, Brute(i + X[k], j + Y[k]) + 1);
			}
			return ans = a;
		};
		
		int answer = Brute(0, 0);
		if(answer >= OO) puts("not possible");
		else printf("%d\n", answer);
	}
	return 0;
}
