#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)6e4 + 10;

int main() {
	int a, b;
	while( scanf("%d %d", &a, &b) ) {
		if(!a && !b) break;
		
		vector<pair<int, int>> ans;
		for(int i = 1; i < nax; ++i) {
			int x = a / i;
			if(x <= b) break;
			int d = 9 * (x - b) * i * i;
			ans.push_back({d, i});
		}
		
		sort(ans.rbegin(), ans.rend());
		debug() << owo(ans);
		if((int)ans.size() == 0) puts("0");
		else if((int)ans.size() == 1) printf("%d\n", ans[0].second);
		else {
			if(ans[0].first == ans[1].first) puts("0");
			else printf("%d\n", ans[0].second);
		}
	}

	return 0;
}
