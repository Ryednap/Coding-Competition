#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
using vvi = vector<vi>;
const int OO = (int)1e6;

int main() {
	int t1, t2;
	while (scanf("%d %d", &t1, &t2) ) {
		if(!t1 && !t2) break;
		
		int n;
		scanf("%d", &n);
		vi w(n);
		vvi c1(n + 1), c2(n + 1);
		
		for(int i = 0; i < n; ++i) {
			scanf("%d", &w[i]);
			vector<int> v(w[i] + 1);
			v[0] = 0;
			for(int j = 1; j <= w[i]; ++j) {
				scanf("%d", &v[j]);
			}
			c1[i] = v;
			for(int j = 1;j <= w[i]; ++j) {
				scanf("%d", &v[j]);
			}
			c2[i] = v;
		}
		
		vector<vvi> dp (n, vvi(t1 + 10, vi(t2 + 10, -1)));
		
		function < int (int, int, int) > Brute = [&] (int i, int j, int k) {
			if(j < 0 || k < 0) return OO;
			if(i == n) return 0;
			
			int  & ans = dp[i][j][k];
			if(ans != -1) return ans;
			
			ans = OO;
			for(int l = 0; l <= w[i]; ++l) {
				int m = w[i] - l;
				ans = min( ans, 
						Brute(i + 1, j - l, k - m) + c1[i][l] + c2[i][m]
						);
			}
			return ans;
		};
		
		vector<int> count(n, 0);
		function < void (int, int, int) > Build = [&] (int i, int j, int k) {
			if(i == n) return;
			
			int ans = Brute(i ,j, k);
			for(int l = 0; l <= w[i]; ++l) {
				int m = w[i] - l;
				if(ans == Brute(i + 1,j - l, k - m) + c1[i][l] + c2[i][m]) {
					count[i] = l;
					Build(i + 1, j - l, k - m);
					return;
				}
			}
		};
		
		int answer = Brute(0, t1, t2);
		Build(0, t1, t2);
		printf("%d\n", answer);
		printf("%d", count[0]);
		for(int i = 1; i < n; ++i) {
			printf(" %d", count[i]);
		}
		puts("");
	}
	
	return 0;
}
