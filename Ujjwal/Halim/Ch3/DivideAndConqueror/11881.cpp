#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const double EPS = 1e-8;

int main() {
	int T;
	while (scanf("%d", &T) && T) {
		int arr[T + 1];
		for(int i = 0; i <= T; ++i) {
			scanf("%d", &arr[i]);
		}
		
		auto F = [&] (double x) {
			double res = arr[0];
			for(int i = 1; i <= T; ++i) {
				res += arr[i] / pow(1 + x, i);
			}
			return res;
		};
		
		double lo = -0.999, hi = 1;
		if(F(lo) * F(hi) > 0) { // Then no root or too many roots
			bool ok = false;
			while(fabs(lo - hi) > EPS) {
				double mid = (lo + hi) / 2.0;
				if(F(mid) * F(-0.999) <= 0) {
					ok = true;
					break;
				} else if(F(mid) * F(1) <= 0) {
					ok = true;
					break;
				} else {
					lo = mid;
				}
			}
			if(ok) puts("Too many");
			else puts("No");
			continue;
		}
		
		while (fabs(lo - hi) > EPS) {
			double mid = (lo + hi) / 2.0;
			if(F(mid) * F(1) > 0) {
				lo = mid;
				
			} else hi = mid;
		}
		
		printf("%.2f\n", (lo + hi) / 2.0);
		
	}
	return 0;
}
