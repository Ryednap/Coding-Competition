#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
const int OO = (int)1e9;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int d; scanf("%d", &d);
		d /= 100;
		vector<vi> w(10, vi(d));
		for(int i = 9; i >= 0 ; --i) {
			for(int & x : w[i]) {
				scanf("%d", &x);
			}
		}
		
		// dp[i][j] = minimum cost when at the distance of "i" I am at altitude "j"
		vector<vi> dp(d + 1, vi(11, -1));
			
			
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(j < 0 || j > 9) return OO;
			if(i == d) return j == 0 ? 0 : OO;
			
			int & ans = dp[i][j];
			if(ans != -1) return ans;
			ans = OO;
			
			ans = min(ans, Brute(i + 1, j + 1) + 60 - w[j][i]);
			ans = min(ans, Brute(i + 1, j - 1) + 20 - w[j][i]);
			ans = min(ans, Brute(i + 1, j) + 30 - w[j][i]);
			
			return ans;
		};
		
		printf("%d\n", Brute(0, 0));
		puts("");
	}
	return 0;
}
