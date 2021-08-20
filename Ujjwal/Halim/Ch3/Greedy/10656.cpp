#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int N;
	while (scanf("%d", &N) && N) {
		vector<int> ans;
		for(int i = 0; i < N; ++i) {
			int x; 
			scanf("%d", &x);
			if(x) ans.push_back(x);
		}
		
		if((int)ans.size()) {
			printf("%d", ans[0]);
			for(int i = 1; i < (int)ans.size(); ++i) {
				printf(" %d", ans[i]);
			}
			puts("");
			
		} else puts("0");
	}
	return 0;
}
