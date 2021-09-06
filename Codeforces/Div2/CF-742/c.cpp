#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int dp[11][4][4];
int n;
string s;

int solve (int i, int j, int k) {
	if (i == n) return (j == 0 && k == 0);

	int & ans = dp[i][j][k];
	if (ans != -1) return ans;
	int c = (s[i] - '0');
	ans = 0;
	for (int digit = 0; digit < 10; ++digit) {
		for (int other = 0; other < 10; ++other) {
			if (i & 1) {
				int value = other + digit + (k == 1);
				int ones = value % 10; value /= 10;
				int tens = value % 10;
				if(ones == c) {
					ans += solve(i + 1, max(j - 1, 0), tens ? 2 : 0);
				}

			} else {
				int value = other + digit + (j == 1);
				int ones = value % 10; value /= 10;
				int tens = value % 10;
			
				if(ones == c) {
					ans += solve(i + 1, tens ? 2 : 0, max(k - 1, 0));
				}
			}
		}
	}
	return ans;
}


int main () {
	int qq;
	scanf ("%d", &qq);
	while (qq--) {
		cin >> s;
		reverse(s.begin(), s.end());
		n = (int)s.length();
		memset(dp, -1, sizeof(dp));
		printf ("%d\n", max(solve(0, 0, 0) - 2, 0));
	}
	return 0;
}