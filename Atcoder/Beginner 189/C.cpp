#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif



int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for(int & x : v) {
		scanf("%d", &x);
	}
	
	long long answer = 0;
	for(int i = 0 ; i < n ; ++i) {
		int x = v[i];
		int cnt =  0;
		for(int j = i; j >= 0 && x <= v[j]; --j) {
			++cnt;
		}
		for(int j = i + 1; j < n && x <= v[j]; ++j) {
			++cnt;
		}
		answer = max(answer, (long long)cnt * x);
	}
	printf("%lld\n", answer);
	return 0;
}
