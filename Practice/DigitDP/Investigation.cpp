#include <bits/stdc++.h>

const int nax = 1e4 + 10;
int dp[19][2][nax], mod;
std :: string n;

int Mod(int sum) {
	return (sum) % mod;
}

int Brute (int i, int j, int k) {
	if(i == (int)n.length()) return (k == 0);  
	int & ans = dp[i][j][k];
	if(ans != -1) return ans;
	ans = 0;
	for(int digit = 0; digit < 10; ++digit) {
		int here = n[i] - '0';
		if(here == digit) {
			ans += Brute(i + 1, j, Mod(k + digit));
		} else if(digit < here) {
			ans += Brute(i + 1, false, Mod(k + digit));
		} else {
			if(j) break;
			ans += Brute(i + 1, j, Mod(k + digit));
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int l, r; scanf("%d %d %d", &l, &r, &mod);
		std :: string a = std :: to_string(l - 1);
		std :: string b = std :: to_string(r);

		memset(dp, -1, sizeof(dp));
		n  = a;
		int x = Brute(0, 1, 0);
		memset(dp, -1, sizeof(dp));
		n = b;
		int y = Brute(0, 1, 0);
		printf("%d\n", y - x);
	}
	return 0;
}
