#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// classic dp problem

int x, y, n;
int arr[11000];
int dp[11000][3];

int Brute(int i, int j) { // 0 -> C 1 -> j
	if(i == n) {
		return 0;
	}
	
	int & ans = dp[i][j];
	if(ans != -1) return ans;
	
	
	if(arr[i] == 2) {
		int a = Brute(i + 1, 0) + (j == 1 ? y : 0);
		int b = Brute(i + 1, 1) + (j == 0 ? x : 0);	
		return ans = min(a, b);
		
	} else if(arr[i] == 0) {
		return ans = Brute(i + 1, arr[i]) + (j == 1 ? y : 0);
	} else {
		return ans = Brute(i + 1, arr[i]) + (j == 0 ? x : 0);
	}
}

void Solve() {
	scanf("%d %d", &x, &y);
	string s; cin >> s;
	n = (int)s.length();
	
	for(int i = 0; i < n; ++i) {
		if(s[i] == '?') arr[i] = 2; 
		else arr[i] = s[i] == 'J' ? 1 : 0;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", Brute(0, 2));
}

int main() {
	int qq;
	scanf("%d", &qq);
	for(int i = 1; i <= qq; ++i) {
		printf("Case #%d: ", i);
		Solve();
	}
	
	return 0;
}
	
