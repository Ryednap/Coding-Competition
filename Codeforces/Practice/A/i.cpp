#include <bits/stdc++.h>
using namespace std;

bool Cube (auto n) {
	long long lo = 0, hi = 1e4 + 10;
	while (lo <= hi) {
		auto mid = (lo + hi) >> 1;
		if(mid * mid * mid == n) return true;
		else if(mid * mid * mid < n) lo = mid + 1;
		else hi = mid - 1;
	}
	return false;
}

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		long long x;
		scanf("%lld",&x);
		bool ok = false;
		for(int i = 1; i <= (int)1e4; ++i) {
			long long b = i * i * (long long)i;
			if(b >= x) break;
			long long c = x - b;
			if(Cube(c)) {
				ok = true;
				break;
			}
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;	
}
