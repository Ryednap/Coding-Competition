#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main() {
	int x, y;
	vector<array<int, 3>> v;
	int count = 0;
	while (scanf("%d %d", &x, &y) != EOF) {
		v.push_back({x, y, count++});
	}
	
	sort(v.begin(), v.end(), [](array<int, 3> &a, array<int, 3> & b){
		if(a[0] == b[0]) return a[1] > b[1];
		else return a[0] < b[0];
	});
	
	//debug() << owo(v);
	const int n = (int)v.size();
	int dp[n][2];
	for(int i = 0; i < n; ++i) {
		dp[i][0] = 1;
		dp[i][1] = i;
		for(int j = 0; j < i; ++j) {
			if(v[i][0] > v[j][0] && v[i][1] < v[j][1]) {
				if(dp[i][0] < dp[j][0] + 1) {
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = j;
				}
			}
		}
	}
	
	int where = 0;
	for(int i = 1; i < n; ++i) {
		if(dp[where][0] < dp[i][0]) where = i;
	}
	
	printf("%d\n", dp[where][0]);
	vector<int> ans;
	while (dp[where][1] != where) {
		ans.push_back(v[where][2] + 1);
		where = dp[where][1];
	}
	
	ans.push_back(v[where][2] + 1);
	reverse(ans.begin(), ans.end());
	for(int & p : ans) {
		printf("%d\n", p);
	}
	
	return 0;
}
