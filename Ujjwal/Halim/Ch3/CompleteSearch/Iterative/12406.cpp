#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while( qq--) {
		int p, q;
		scanf("%d %d", &p, &q);
		vector<long long> ans;
		for(int i = 0; i < (1 << p); ++i) {
			long long num = 0;
			for(int j = 0; j < p; ++j) {
				if(i & (1 << j)) {
					num = num * 10 + 1;
				} else num = num * 10 + 2;
			}
			if(!(num & ((1 << q) - 1))) ans.push_back(num); // by doing  this there's a lot of difference in time
		}
		sort(ans.begin(), ans.end());
		printf("Case %d: ", ++tt);
		if((int)ans.size() == 0) puts("impossible");
		else if((int)ans.size() == 1) printf("%lld\n",  ans[0]);
		else printf("%lld %lld\n", ans[0], ans.back());
	}
	return 0;
}
