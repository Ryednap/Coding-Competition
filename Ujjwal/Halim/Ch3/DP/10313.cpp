#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int nax1 = 310;
const int nax2 = 1003;
using vll = vector<long long>;

vector<vll> dp(nax1, vll(nax2));
vector<vll> pref(nax1, vll(nax2));

int main() {
	
	dp[0][0] = 1;

	for(int i = 1; i <= 300; ++i) {
		for(int j = 0; j <= 300 - i; ++j) {
			for(int k = 0; k <= 1001; ++k) {
				dp[j + i][k + 1] += dp[j][k];
			}
		}
	}
	
	
	for(int i = 1; i <= 300; ++i) {
		pref[i][0] = 0;
		for(int j = 1; j <= 1001; ++j) {
			pref[i][j] += pref[i][j - 1] + dp[i][j];
		}
	}
	
	//debug() << owo(dp[17]);
	//debug() << owo(pref[17]);
	
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		vector<int> v;
		int t;
		while (ss >> t) {
			v.push_back(t);
		}
		
		//debug() << owo(v);

		const int n = (int)v.size();
		if(n == 3 && v[1] < v[2]) {
			swap(v[1], v[2]);
		}
		
		
		
		if(n == 1) {
			if(v[0] == 0) printf("%d\n", 1);
			else printf("%lld\n", pref[v[0]][300]);
		} else if(n == 2 || v[2] == 0) {
			if(v[0] == 0) printf("%d\n", 1);
			else printf("%lld\n", pref[v[0]][v[1]]);
			
		} else {
			if(v[0] == 0) printf("%d\n", v[2] == 0 ? 1 : 0);
			else printf("%lld\n", pref[v[0]][v[1]] - pref[v[0]][v[2] - 1]);
		}
	}
	return 0;
}

// corner cases the case with 0 as the input
// the case with (l, r) = (0, r)
// initlly 2 mistake the case of 0 and the ranges can be of order 1e3;
