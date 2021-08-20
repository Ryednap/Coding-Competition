#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// 1 WA due to #warning
// O(30n) :- recommended

int main() {
	int n, tt = 0;
	while (scanf("%d", &n) && n != -1) {
		double l[n];
		int g[n], y[n], r[n];
		for(int i = 0; i < n; ++i) {
			scanf("%lf %d %d %d", &l[i], &g[i], &y[i], &r[i]);
		}
		
		vector<int> ans;
		for(int i = 30; i <= 60; ++i) {
			bool ok = true;
			for(int j = 0; j < n; ++j) {
				const int a = g[j] * i, b = y[j] * i, c = r[j] * i;
				int x = l[j] * 60 * 60;
				
				int sum = a + b + c;

				x = (x % sum);
		#warning satisfy the condition
		
				if(x > a) x -= a;
				else continue;
				if(x > b) x -= b;
				else continue;
				if(x == c) continue;
				ok = false;
				break;
			}
			if(ok) ans.push_back(i);
		}
		
		printf("Case %d:", ++tt);
		for(int i = 0; i < (int)ans.size() ;) {
			int start = ans[i];
			int end = ans[i];
			if(i == 0) printf(" ");
			else printf(", ");
			i = i + 1;
			
			while(i < (int)ans.size() && ans[i] == end + 1) end = ans[i], ++i;
			
			if(start != end) printf("%d-%d", start, end);
			else printf("%d", start);
		}
		if((int)ans.size() == 0) printf(" No acceptable speeds.");
		puts("");
		
	}
	return 0;
}
