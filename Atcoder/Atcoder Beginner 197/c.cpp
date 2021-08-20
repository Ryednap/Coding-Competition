#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif




int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	
    int answer = (int)2e9;
	
	for(int i = 0; i < (1LL << (n - 1)); ++i) {
		int res = 0, x = 0;
		for(int j = 0; j <= n; ++j) {
			if(j < n) x |= arr[j];
			if(j == n || (i & (1 << j))) {
				res ^= x;
				x = 0;
			}
		}
		
		answer = min(answer, res);
		
	}
				
	printf("%d\n", answer);
	return 0;
}
