#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
 * A must to do problem. Problem of these kind are known as MKP (Multiple Knapsach Problem) where we have n items and m knapsack. here m = 2.
 * 
 */

#define f first
#define s second

using vi = vector<int>;
using vvi = vector<vi>;

const int OO = (int)1e4;
int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int m, x;
		scanf("%d", &m);
		m = m * 100;
		vi v;
		while (scanf("%d", &x) && x) {
			v.push_back(x);
		}
		
		const int n = (int)v.size();
		vector<vvi> dp (n, vvi(m + 10, vi(m + 10, -1)));
		
	}
					
	return 0;
}


/*

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i: ++j) {
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1)
			}
		}

		for(int j = 0; j < i; ++j) {
			if(arr[i] > arr[j] && dp[i] == dp[j] + 1) {
				count[i] += count[j];
			}
		}
	}




*/
