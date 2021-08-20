#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (scanf("%d",&n) != EOF) {
		int arr[n];
		for(int i = 0 ; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n);
		
		int m; scanf("%d", &m);
		int lo = 0, hi = (int)1e9;
		for(int i = 0; i < n; ++i) {
			int x = arr[i];
			int y = *lower_bound(arr, arr + n, m - x);
			if(x + y == m) {
				if(x > y) swap(x, y);
				if(y - x < hi - lo) {
					hi = y;
					lo = x;
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n", lo, hi);
		puts("");
	}
			
	return 0;
}
