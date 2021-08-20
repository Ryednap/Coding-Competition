#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second
           //*
// A B C | D E F G

int main() {
	int n = 10;
	vector<int> v = {5, 20, -1, 34, 23, 12, 5, 87, 45 , 34};
	
	vector<int> dp(n + 1, 100);
	dp[0] = -100;
	
	debug() << owo(v);
	
	for(int i = 0; i < n; ++i) {
		debug() << owo(dp);
		auto itr = upper_bound(dp.begin(), dp.end(), v[i]);
		if(itr != dp.end()) {
			*itr = v[i];
		}
	}
	
	return 0;
}
