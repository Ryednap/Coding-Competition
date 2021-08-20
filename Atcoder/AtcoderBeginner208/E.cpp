#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = 20;
std :: string n;

int dp[nax][2];

int Brute (int i, int j) {
	if(i == n.length()) return 0;
	int & ans = dp[i][j];
	if(ans != -1) return ans;
	ans = 0;
	for(int digit = 0; digit < 10; ++digit) {
		int here = n[i] - '0';
		if(digit > here) {	
			if(j) break;
			ans += Brute(i + 1, j) + digit;

		} else if(digit == here) ans += Brute(i + 1, j) + digit;
		else ans += Brute(i + 1, false) + digit;
	}
	return ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	std :: string a, b;
	std :: cin >> a >> b;
	n = a;
	int x = Brute(0, 1);
	n = b;
	memset(dp, -1, sizeof(dp));
	int y = Brute(0, 1);
	printf("%d\n", y - x);
	printf("%d %d\n", y, x);
	return 0;
}