#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<float>;
using vvd = vector<vd>;

#define f first
#define s second

int main() {
	int n, x;
	while (scanf("%d %d", &n, &x)) {
		if(!n && !x)
			break;
		
		--x;
		vi a(n);
		for (int i = 0 ; i < n; ++i) {
			float y; 
			scanf("%f", &y);
			a[i] = round(y * 100);
		}
		
		const int OO = (int)1e9;
		vvi dp(n + 1, vi(100 * 110, -1));
		function < int (int, int) > solve = [&] (int i, int j) {
			if(i == n)
				return j >= 5000 ? j : OO;
			
			int & ans = dp[i][j];
			if(ans != -1)
				return ans;
			
			if(i == x)
				return ans = solve(i + 1, j + a[i]);
			
			return ans = min( solve(i + 1, j + a[i]), solve(i + 1, j));
		};
		
		int value = solve(0, 0); 
		printf("%.2lf\n", (a[x] * 100.0) / (double) value - 1e-5);
	}

	return 0;
}
