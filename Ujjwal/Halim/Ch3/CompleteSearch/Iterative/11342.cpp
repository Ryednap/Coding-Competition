#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)1e9;
int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n; scanf("%d", &n);
		array<int, 3> ans = {nax, nax, nax};
		for(int i = 0; i * i <= n; ++i) {
			for(int j = i; i * i +  j * j <= n; ++j) {
				int k = n - i * i - j * j;
				assert(k >= 0);
				int c = sqrt(k);
				if(c * c == k) {
					array<int, 3> ar = {i, j, c};
					sort(ar.begin(), ar.end());
					ans = min(ans, ar);
				}
			}
		}
		if(ans[0] == nax) puts("-1");
		else printf("%d %d %d\n", ans[0], ans[1], ans[2]);
	} 
		
	return 0;
}
