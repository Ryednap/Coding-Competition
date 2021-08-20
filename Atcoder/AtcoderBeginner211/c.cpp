#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pii>;

#define f first
#define s second

const int mod = (int)1e8;
const int nax = (int)1e5 + 10;
int Add(int a, int b) {
	return (a + b) % mod;
}
int Mul(int a, int b) {
	return ((long long)a * b) % mod;
}

string a = "chokudai";
string b;
int dp[nax][10];

int brute(int i, int j) {
	if(i == (int)a.length())
		return 1;
	if(j == (int)b.length())
		return 0;

	int & ans = dp[i][j];
	if(ans != -1)
		return ans;
	ans = 0;
	if(a[i] == b[j])
		ans = Add(ans, brute(i + 1, j + 1));
	ans = Add(ans, brute(i, j + 1));
	return ans;
}

int main() {
	cin >> b;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", brute(0, 0));
	return 0;
}	
