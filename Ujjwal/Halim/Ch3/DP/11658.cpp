#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
using vd = vector<double>;
const double OO = 1e8;

// There is a bit of automatic error by 1e-2 by which the code is showing WA.

int main() {
	int n, x;
	while (scanf("%d %d", &n, &x) && n) {
		vd arr(n);
		for(auto &e : arr) {
			scanf("%lf", &e);
		/* 	e = e * 100; */
			e = round(e * 100); // Integer rounding error take care always It took me 4 WA and after leaving this problem and
								// solving a much general problem in the future I got this error.
		}

		--x; // 0 based indexing
		vector<vi> dp(n, vi(101 * 100, -OO));
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(i == n) {
				if(j > 5000) return j;
				else return (int)OO;
			}
			
			int & ans = dp[i][j];
			if(ans > -OO) return ans;
			
			if(i == x) return ans = Brute(i + 1, j + arr[i]);
			else {
				return ans = min(Brute(i + 1, j), Brute(i + 1, j + arr[i]));
			}
		};
		
		double answer = (arr[x] * 100.0) / Brute(0, 0) - 1e-5;
		cout << std :: fixed << std :: setprecision(2) <<  answer << endl;;
	}
	
	return 0;
}
