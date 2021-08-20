#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


using vi = vector<long long>;

int main() {
#define int long long
	int qq;
	scanf("%lld", &qq);
	while (qq--) {
		int n;
		scanf("%lld", &n);
		vi a(n), b(n);
		for(int i=0; i < n; ++i)  {
			scanf("%lld",&a[i]);
		}
		for(int i =0; i <n; ++i) {
			scanf("%lld",&b[i]);
		}
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		for(int i = 1; i < n; ++i) {
			a[i] += a[i - 1];
			b[i] += b[i - 1];
		}

		int k = n - n / 4;
		if(a[k - 1] >= b[k - 1]) {
			puts("0");
		} else {
			int lo = n, hi = (int)1e9;
			int ans = -1;
			while (lo <= hi) {
				int mid = lo + ((hi - lo) >> 1);
				int kk = mid - mid / 4;

				int scoreb = 0;
				if(kk > n) {
					scoreb = b[n - 1];
				} else scoreb = b[kk - 1];
				int add = mid - n;
				int scorea = 0;
				if(add >= kk) {
					scorea = 100 * kk;
				} else {
					scorea = 100 * add + a[kk - add - 1];
				}
				if(scorea >= scoreb) {
					ans = mid;
					hi = mid - 1;
				} else lo = mid + 1;
			}
			printf("%lld\n", ans - n);
		}
	}
	return 0;
}