#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
const int nax = (1 << 8) + 10;
const int OO = (int)1e9;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		vector<vi> grid(n, vi(n));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d", &grid[i][j]);
			}
		}

		int dp[nax][nax];
		for(int i = 0; i < nax; ++i) {
			for(int j = 0; j < nax; ++j) {
				dp[i][j] = -OO;
			}
		}
		
		const int limit = (1 << n) - 1;
		function <int(int, int)> Brute = [&] (int i, int j) {
			if(i == limit) return 0;
			
			int & ans = dp[i][j];
			if(ans != -OO) return ans;
			
			for(int row = 0; row < n; ++row) {
				if(i & (1 << row)) continue;
				int Bob = OO;
				for(int col = 0; col < n; ++col) {
					if(j & (1 << col)) continue;
					Bob = min(Bob, Brute(i | (1 << row), j | (1 << col)) + grid[row][col]);
				}
				ans = max(ans, Bob);
			}
			
			return ans;	
		};
		
		int answer = Brute(0, 0);
		printf("%d\n", answer);
	}
	return 0;
}
