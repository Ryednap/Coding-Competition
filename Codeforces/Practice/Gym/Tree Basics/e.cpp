#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)2e5 + 10;

int main() {
	int n, k;
	scanf("%d %d", &n , &k);
	if(k == 2) {
		printf("%d\n", n - 1);
		for(int i = 1; i < n - 1; ++i) {
			printf("%d %d\n", i, i + 1);
		}
	} else {
		vector<int> edges[n + 1];
		for(int i = 1; i <= k; ++i) {
			edges[1].push_back(i + 1);
		}
		int rem = n - 1 - k;
		int curr = k + 1;
		for(int i = 2; i <= k; ++i) {
			edges[i].push_back(cu
	}
	
	
	return 0;
}
