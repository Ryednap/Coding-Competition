#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)1e4;

int main() {
#define int long long
	double n, m;
	scanf("%lf %lf", &n, &m);
	int a = n * (int)1e6;
	int b = m * (int)1e6;
	
	vector<array<int, 4>> ans;
	for(int x = 1; x <= cbrt(b); ++x) {
		for(int y = cbrt(b) ; y <= cbrt(b * b) ; ++y) {
			for(int z = cbrt(b * b) ; z <= b ; ++z) {
				debug() << owo(x) owo(y) owo(z);
				if(x * y * z == (x + y + z) * nax) {
					int lo = min(x * y * z, (x + y + z) * nax);
					int hi = max(x * y * z, (x + y + z) * nax);
					if(lo >= a && hi <= b) {
						array<int, 4> is = {x, y, z};
						ans.push_back(is);
					}
				}
			}
		}
	}
	debug() << owo(ans);
	return 0;
}
