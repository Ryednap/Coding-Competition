#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
using vvi = vector<vi>;

// A direct simple problem. O(n * t * p) complexity and O(n * t) memory

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, t, p;
		scanf("%d %d %d", &n, &t, &p);
		
		vvi dp(n, vi(t + 10, -1));
		
		//debug() << owo(n) owo(t) owo(p);
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(j < 0) return 0; 
			if(i == n) return j == 0 ? 1 : 0;
	
			int & ans = dp[i][j];
			if(ans != -1) return ans;
			
			ans = 0;
			for(int k = p; k <= 70; ++k) {
				ans += Brute(i + 1, j - k);
			}
			
			return ans;
		};
		
		printf("%d\n", Brute(0, t));
		//debug() << owo(dp);
	}
	return 0;
}
