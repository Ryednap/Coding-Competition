#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int OO = (int)1e9;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		vector<int> dp1(n + 1, OO), dp2(n + 1, -OO);
		dp1[0] = -OO;
		dp2[0] = OO;
		
		for(int i = 0; i < n; ++i) {
			auto itr = upper_bound(dp1.begin(), dp1.end(), arr[i]);
			if(itr != dp1.end() && *(itr - 1) < arr[i]) {
				*itr = arr[i];
			}
		}
		
		for (int i = n - 1; i >= 0; --i) {
			int lo = 0, hi = n;
			int pos = -1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if(dp2[mid] < arr[i]) {
					pos = mid;
					lo = mid + 1;
					
				} else hi = mid - 1;
			}
			
			
			
		}

	}
	return 0;
}
