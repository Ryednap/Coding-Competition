#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
// 3 WA due to that fact I can't write "Peter you shouldn't have played billiard that much" fuck.
// Also learned that have a threshold when outputing floating point received errnous WA. Have 1e-9 as threshold.
const int OO = (int)1e5;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vi> arr(n, vi(m));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		vector<vi> dp(n + 1, vi(2 * m + 1, -1));
		
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(j > m) return -OO;
			if(i == n) return 0;
			
			int & ans = dp[i][j];
			
			if(ans != -1) return ans;
			ans = -OO;
			for(int k = 0; k < m; ++k) {
				if(arr[i][k] >= 5)
					ans = max(ans, Brute(i + 1, j + k + 1) + arr[i][k]);
			}
			
			return ans;
		};
		
		double answer = Brute(0, 0) / (double) n;
		//if(answer > 5 && answer - 5.12 <= 1e-6) debug() << owo(n) owo(Brute(0, 0)) owo(answer) owo(arr) ;
		if(answer <= 0) puts("Peter, you shouldn't have played billiard that much.");
		else printf("Maximal possible average mark - %.2lf.\n", answer + 1e-9);
	}
		
	return 0;
}
