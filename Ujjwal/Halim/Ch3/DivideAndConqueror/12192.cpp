#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(qq * n * log(m)) complexity just passes the time limit not very optimal :>

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m)) {
		if(!n && !m) break;
		int arr[n][m];
		for(int i = 0; i < n; ++i) {#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m)) {
		if(!n && !m) break;
		int arr[n][m];
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		int qq; scanf("%d", &qq);
		while (qq--) {
			int l, r;
			scanf("%d %d", &l, &r);
			
			int ans = 0;
			for(int i = 0 ; i < n; ++i) {
				int j = lower_bound(arr[i], arr[i] + m, l) - arr[i];
				int lo = 0, hi = min(n - i - 1, m - j - 1);
				int here = -1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					if(arr[i + mid][j + mid] <= r) {
						lo = mid + 1;
						here = mid;
						
					} else hi = mid - 1;
				}
				ans = max(ans, here + 1);
			}
			printf("%d\n",ans);
		}
		puts("-");
	}
			
	return 0;
}

			for(int j = 0; j < m; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		int qq; scanf("%d", &qq);
		while (qq--) {
			int l, r;
			scanf("%d %d", &l, &r);
			
			int ans = 0;
			for(int i = 0 ; i < n; ++i) {
				int j = lower_bound(arr[i], arr[i] + m, l) - arr[i];
				int lo = 0, hi = min(n - i - 1, m - j - 1);
				int here = -1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					if(arr[i + mid][j + mid] <= r) {
						lo = mid + 1;
						here = mid;
						
					} else hi = mid - 1;
				}
				ans = max(ans, here + 1);
			}
			printf("%d\n",ans);
		}
		puts("-");
	}
			
	return 0;
}
