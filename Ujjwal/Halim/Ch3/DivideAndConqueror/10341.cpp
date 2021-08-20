#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const double EPS = 1e-8;

// A simple note for root finding.
// It's not like a trivial Binary search.
// Here we need to compare the sign of the two extremes in which the root of the equation must lie
// My 2 attemps were wrong because of this.

int main() {
	int p, q, r, s, t, u;
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
	

		auto F = [&] (long double x) {
			return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
		};
		
		if(F(0) * F(1) > 0) {
			puts("No solution");
			continue;
		}
				
		double lo = 0, hi = 1;	
		
		while (fabs(lo - hi) >= EPS) {
			long double mid = (lo + hi) / (long double) 2.0;
			if(F(0) * F(mid) > 0) {
				lo = mid;
				
			} else hi = mid;
		}
		
		printf("%.4f\n", (lo + hi) / 2.0);
	}
				
	return 0;
}
