#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf ("%d", &n);
		int arr[n], prev = 0;
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			arr[i] = x - prev;
			prev = x;
		}
		
		
		auto F = [&] (int x) {
			for(int i = 0; i < n; ++i) {
				if(arr[i] > x) return false;
				if(arr[i] < x) continue;
				if(arr[i] == x) --x;
			}
			return true;
		};
		
		int lo = 0, hi = (int)1e8;
		int ans = -1;
		while (lo <= hi) {
			int mid = lo + ((hi - lo) >> 1);
			if(F(mid)) {
				ans = mid;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		
		assert(ans != -1);
		printf("Case %d: %d\n", ++tt, ans);
	}
		
	return 0;
}
