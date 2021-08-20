#include <bits/stdc++.h>
using namespace std;

// An easier solution exits
// 13.5 min

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		long long k;
		scanf("%d %lld", &n, &k);
		vector<long long> v(n);
		for(auto & x : v) scanf("%lld", &x);
		map<vector<long long>, bool> done;
		while(!done[v] && k) {
			done[v] = true;
			long long maxi = *max_element(v.begin(), v.end());
			for(int i = 0; i < n; ++i) {
				v[i] = maxi - v[i];
			}
			--k;
		}
		if(k & 1) {
			long long maxi = *max_element(v.begin(), v.end());
			for(int i = 0; i < n; ++i) {
				v[i] = maxi - v[i];
			}
		}
		for(long long & x : v) {
			printf("%lld ", x);
		}
		puts("");
	}
			
	return 0;	
}
