#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q, tt = 0;
	while (scanf("%d %d", &n, &q)) {
		if(!n && !q) break;
		vector<int> v(n);
		for(int & x : v) {
			scanf("%d", &x);
		}
		
		sort(v.begin(), v.end());
		printf("CASE# %d:\n", ++tt);
		while (q--) {
			int x; scanf("%d", &x);
			auto itr = lower_bound(v.begin(), v.end(), x);
			if((*itr == x)) {
				printf("%d found at %d\n", x, (int)(itr - v.begin() + 1));
			} else printf("%d not found\n", x);
		}
	}
			
	return 0;
}
