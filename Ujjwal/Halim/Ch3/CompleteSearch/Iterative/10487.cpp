#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n ^ 2 * q) per query
// A much faster would be precomputation with binary search
// O(q * log(n ^ 2) + n ^ 2) per query

const int OO = (int)1e9 + 10;
int main() {
	int  n, tt = 0;
	while (scanf("%d", &n) && n) {
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		int m; scanf("%d", &m);
		printf("Case %d:\n", ++tt);
		while (m--) {
			int x; scanf("%d", &x);
			int ans = -1;
			int what = OO;
			for(int i = 0; i < n; ++i) {
					for(int j = i + 1; j < n; ++j) {
						int value = abs(arr[i] + arr[j] - x);
						if(value < what) what = value, ans = arr[i] + arr[j]; 
					}
			}
			printf("Closest sum to %d is %d.\n", x, ans);
		}
	}
			
	return 0;
}
