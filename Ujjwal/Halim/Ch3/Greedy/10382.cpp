#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<double, double>;
#define f first
#define s second

// Nice geometrical Problem
// Watch out for overflowsin r * r and w * w;

int main() {
	int n, l, w;
	while (scanf("%d %d %d", &n, &l, &w) != EOF) {
		vector<pii> arr;
		for(int i = 0; i < n; ++i) {
			long long x, r;
			scanf("%lld %lld", &x, &r);
			if(2 * r >= w) {
				double d = sqrt(r * r - (w * w) / 4.0); // geometry
				//if(i == 1) debug() << owo(d);
				arr.emplace_back(x - d, x + d);
			}
			
		}
		sort(arr.begin(), arr.end(), [](const pii & a, const pii & b) {
			if(a.f == b.f) return a.s > b.s;
			return a.f < b.f;
		});
		//debug() << owo(arr);
		double req = 0;
		int ok = 1;
		pii maybe = {-1, -1};
		set<pii> ans;
		
		for(int i = 0; i < (int)arr.size(); ++i) {
			if(req >= l) break;
			if(arr[i].f <= req && arr[i].s >= req) {
				if(arr[i].s > maybe.s) maybe = arr[i];
				
			} else if(arr[i].f > req) {
				if(maybe.f > req || maybe.s < req) ok = false;
				ans.insert(maybe);
				req = maybe.s;
				maybe = arr[i];
			}
		}
		if(req < l && maybe.f <= req && maybe.s >= req) {
			req = maybe.	s;
			ans.insert(maybe);
		}
		ok &= (req >= l);
		//debug() << owo(ans);
		if(ok) printf("%d\n", (int)ans.size());
		else puts("-1");
	}
			
	return 0;
}
