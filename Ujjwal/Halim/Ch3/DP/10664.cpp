#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main() {
	int qq;
	char buff;
	scanf("%d%c", &qq, &buff);
	while (qq--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int x, total = 0;
		vector<int> v;
		while (ss >> x) {
			v.push_back(x);
			total += x;
		}
		
		const int n = (int)v.size();
		vector<vector<int>> dp(n, vector<int> (total + 10, -1));
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(i == n) return (j == total - j ? 1 : 0);
			int & ans = dp[i][j];
			if(ans != -1) return ans;
			return ans = Brute(i + 1, j) | Brute(i + 1, j + v[i]);
		};
		
		if(Brute(0, 0)) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
