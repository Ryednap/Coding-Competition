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
const int nax = 1 << 8;

int main() {
	int n, m;
	scanf("%d %d",&n, &m);
	vector<string> v(n);
	for(string & s : v) {
		cin >> s;
	}
	int dp[10][10][10][nax][nax];
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	function < int (int, int, int, int , int)> brute = [&] (int i, int j, int k, int row, int col) {
		if(k == m) 
			return 1;

		int & ans = dp[i][j][k][row][col];
		if(ans != -1)
			return ans;
		ans = 0;

		auto valid = [&] (int x, int y) {
			if(x < 0 || y < 0 || x >= n || y >= m)
				return false;
			if(row & (1 << x) && col & (1 << y))
				return false;
			if(v[x][y] != '.')
				return false;
			return true;
		};

		for(int it = 0 ; it < 4; ++it) {
			int RR = i + dx[it];
			int CC = j + dy[it];
			if(valid(RR, CC))
				ans +=  brute(RR, CC, k - 1, row | (1 << RR), col | (1 << CC)) + 
							brute(RR, CC, k, row | (1 << RR), col | (1 << CC));
		}
		return ans;
	};
	memset(dp, -1, sizeof(dp));
	int ans = -1;
	for(int i = 0; i < n; ++i) {

		for(int j = 0; j < n; ++j){
			if(v[i][j] == '.')
				ans = brute(i, j, 0, 0, 0);
			if(ans != -1)
				break;
		}
		if(ans != -1)
			break;
	}
	printf("%d\n", max(ans, 0));
	return 0;
}