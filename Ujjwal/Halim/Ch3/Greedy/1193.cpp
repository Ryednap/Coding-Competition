#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define float long double
using pii = pair<float, float>;
using piii = pair<int, pii>;

#define f first
#define s second

static inline bool Intersect(const pii & a, const pii & b) {
	if(a.s < b.f) return false;
	if(a.f > b.s) return false;	
	return true;
}



int main() {
	int n, d, tt = 0;
	while (scanf("%d %d", &n, &d)) {
		if(!n && !d) break;
		
		vector<pii> arr(n);
		d = d * d;
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			if(y * y > d) {
				ok = false;
			} else {
				float p = x + sqrt(d - y * y);
				float q = x - sqrt(d - y * y);
				arr[i].f = min(p, q);
				arr[i].s = max(p, q);
			}
		}
		
		if(!ok) {
			printf("Case %d: -1\n", ++tt);
			continue;
		}

		sort(arr.begin(), arr.end(), [&] (const pii & a, const pii & b){
			if(a.f == b.f)
				return a.s > b.s;
			return a.f < b.f;
		});
		int ans = 0;
		float r  = -1e9;
		for(int i = 0; i < n; ++i) {
			if(arr[i].f >= r) {
				r = arr[i].s;
				++ans;
			}
			r = min(r, arr[i].s);
		}
		printf("Case %d: %d\n", ++tt, ans);
	}
		
	return 0;
}
