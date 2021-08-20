#include <bits/stdc++.h>

// curr length, previous digit, limit
int dp[20][10][2][2][20];
std :: string a, b;

int Brute(int i, int j, int k, int l, int m) {
	printf("i : %d previous :  %d length : %d\n", i, j, m);
	if(i == (int) b.length()) return m;

	int & ans = dp[i][j][k][l][m];
	if(ans != -1) return ans;
	for(int digit = 0; digit < 10; ++digit) {

		int lower = a[i] - '0';
		int upper = b[i] - '0';
		//printf("%d %d %d\n", digit, lower, upper);
		if(lower == digit) {
			if(upper == digit) {
				// ans = std :: max(ans, Brute(i + 1, digit, k, l, m));
				ans = std :: max(ans, Brute(i + 1, digit, k, l, m + digit > j));

			} else if(upper > digit) {
				// ans = std :: max(ans, Brute(i + 1, digit, false, l, m));
				ans = std :: max(ans, Brute(i + 1, digit, false, l, m + digit > j));

			} else if(upper < digit) {
				if(k) continue;
				// ans = std :: max(ans, Brute(i + 1, digit, k, l, m));
				ans = std :: max(ans, Brute(i + 1, digit, k, l, m + digit > j));
			}

		} else if(upper == digit) {
			if(lower > digit) {
				if(l) continue;
				// ans = std :: max(ans, Brute(i + 1, digit, k, l, m));
				ans = std :: max(ans, Brute(i + 1, digit, k, l, m + digit > j));

			} else if(lower < digit) {
				// ans = std :: max(ans, Brute(i + 1, digit, k, false, m));
				ans = std :: max(ans, Brute(i + 1, digit, k, false, m + digit > j));
			}

		} else if(lower > digit) {
			if(upper > digit) { // smaller than both
				if(l) continue;
				// ans = std :: max(ans, Brute(i + 1, digit, false, l, m));
				ans = std :: max(ans, Brute(i + 1, digit, false, l, m + digit > j));

			} else if(upper < digit) {
				if(k || l) continue;
				// ans = std :: max(ans, Brute(i + 1, digit, k, l, m));
				ans = std :: max(ans, Brute(i + 1, digit, k, l, m + digit > j));
			}

		} else if(lower < digit) {
			if(upper > digit) { // digit between upper and lower
				// ans = std :: max(ans, Brute(i + 1, digit, false, false, m));
				ans = std :: max(ans, Brute(i + 1, digit, false, false, m + digit > j));
			} else if(upper < digit) {
				if(k) continue;
				// ans = std :: max(ans, Brute(i + 1, digit, k, false, m));
				ans = std :: max(ans, Brute(i + 1, digit, k, false, m + digit > j));
			}
		}
	}
	return ans;
}


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--){
		std :: cin >> a >> b;
		while (a.length() != b.length()) {
			a = '0' + a;
		}
		std :: cout << a << ' ' << b << '\n';
		memset(dp, -1, sizeof(dp));
		printf("%d\n", Brute(0, 0, 1, 1, 0));
	}
}