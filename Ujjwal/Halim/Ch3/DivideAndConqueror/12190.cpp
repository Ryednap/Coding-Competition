#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A very nice problem. 
// Requires thining from the different angle. Think not in terms of consumption but price of consumption and have a F and F inverse to help
// also This function should operate on double.

int main() {
	int A, B;
	while (scanf("%d %d", &A, &B)) {
		if(!A && !B) break;
		
		const long long Watt[] = {100, 9900, 990000};
		const long long Price[] = {2, 3, 5, 7};
		
		auto F = [&] (double x) {
			double value = 0;
			for(int i = 0; i < 3; ++i) {
				if(x < Watt[i]) {
					value += x * Price[i];
					x = 0;
					break;
				} else {
					value += Watt[i] * Price[i];
					x -= Watt[i];
				}
			}
			
			return value + x * Price[3];
		};
			
		
		auto G = [&] (double x) { // Inverse function of F
			double res = 0;
			for(int i = 0; i < 3; ++i) {
				int total = Watt[i] * Price[i];
				if(x < total) {
					res += x / Price[i];
					x = 0;
					break;
					
				} else {
					res += Watt[i];
					x -= total;
				}
			}
			
			return res += x / Price[3];
		};
		
		int lo = 0, hi = (int)1e9;
		int ans = -1;
		while (lo <= hi) { // Guesing A
			int mid = lo + ((hi - lo) >> 1);
			double x = G(mid);
			double y = G(mid + B);

			if(F(x + y) == A) {
				ans = mid;
				break;
			} else if(F(x + y) < A) {
				lo = mid + 1;
				
			} else hi = mid - 1;
		}
		
		printf("%d\n", ans);
	}
				
	
	
	return 0;
}
