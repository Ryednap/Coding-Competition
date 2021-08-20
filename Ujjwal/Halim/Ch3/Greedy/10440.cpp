#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, t, m;
		scanf("%d %d %d", &n, &t, &m);
		int arr[m];
		for(int i = 0; i < m; ++i) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + m);
		
		int ans = 0, turn = 0;
		if(n > m) {
			ans = arr[m - 1] + t;
			turn = 1;
			
		} else if(m % n == 0) {
			int c = 0;
			turn = m / n;
			for(int i = 0; i < m; ++i) {
				++c;
				if(c == n) {
					if(ans >= arr[i]) ans += 2 * t;
					else ans = arr[i] + 2 * t;
					c = 0;
				}
			}
			if(c != 0) {
				if(ans >= arr[n - 1]) ans +=  t;
				else ans = arr[n - 1] + t;
				
			} else ans -= t;
			
		} else {
			int r = m % n, c = 0;
			turn = (m + n - 1) / n;
			ans += arr[r - 1] + 2 * t;
			for(int i = r; i < m; ++i) {
				++c;
				if(c == n) {
					if(ans > arr[i]) ans += 2 * t;
					else ans = arr[i] + 2 * t;
					c = 0;
				}
			}
			
			if(c != 0) {
				if(ans >= arr[n - 1]) ans +=  t;
				else ans = arr[n - 1] + t;
				
			} else ans -= t;		
			
		}
		
		printf("%d %d\n", ans, turn);
	}
	return 0;
}
