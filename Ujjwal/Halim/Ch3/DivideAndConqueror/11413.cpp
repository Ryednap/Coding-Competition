#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int arr[n];
		int lo = 0, hi = (int)1e9 + 10;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			lo = max(lo, arr[i]);
		}
		
		auto F = [&] (int x) {
			int sum = 0, cnt = 1;
			for(int i = 0; i < n; ++i) {
				if(sum + arr[i] > x) {
					sum = arr[i];
					++cnt;
				} else sum += arr[i];
			}
			
			return cnt <= m;
		};
			
		
		int ans = -1;
		while (lo <= hi) {
			int mid = lo + ((hi - lo) >> 1);
			if(F(mid)) {
				hi = mid - 1;
				ans = mid;
			} else lo = mid + 1;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
