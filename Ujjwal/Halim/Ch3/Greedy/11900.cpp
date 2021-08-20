#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int qq;
	scanf("%d", &qq);
	for(int tt = 1; tt <= qq; ++tt) {
		printf("Case %d: ", tt);
		int n, p, q;
		scanf("%d %d %d",&n, &p, &q);
		int arr[n];
		for(int i = 0 ; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr +n);
		
		int ans = 0, total = 0;
		for(int i = 0; i < min(n, p); ++i) {
			if(total + arr[i] > q) break;
			++ans;
			total += arr[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
