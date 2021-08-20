#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using pi = pair<int, int>;
using vi = vector<int>;

// 1 WA due to extra break in end

int main() {
	int t, w, tt = 0;
	while (scanf("%d %d", &t, &w) != EOF) {
		if(tt) puts("");
		else tt = 1;
		
		int n;
		scanf("%d", &n);
		vector<pi> arr(n);
		for(auto & p : arr) {
			scanf("%d %d", &p.f, &p.s);
		}
		
		vector<vi> dp(n + 1, vi(t + 100, -1));
		
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(i == n) return 0;
			int & ans = dp[i][j];
			if(ans != -1) return ans;
			
			int a = Brute(i + 1, j);
			int b = 0;
			if(j >= 3 * w * arr[i].f) b = Brute(i + 1, j - 3 * w * arr[i].f) + arr[i].s;
			return ans = max(a, b);
		};
		
		vector<int> box;
		
		function < void (int, int) > Build = [&] (int i, int j) {
			if(i == n) return;
			
			int ans  = Brute(i, j);
			
			if(ans == Brute(i + 1, j)) Build(i + 1, j);
			else {
				box.push_back(i);
				Build(i + 1, j - 3 * w * arr[i].f);
			}
		};
		
		int answer = Brute(0, t);
		Build(0, t);
		
		printf("%d\n", answer);
		printf("%d\n", (int)box.size());
		for(auto & x : box) {
			printf("%d %d\n", arr[x].f, arr[x].s);
		}
	}
	return 0;
}
