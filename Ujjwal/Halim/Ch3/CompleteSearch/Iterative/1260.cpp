#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			int cnt = 0;
			for(int j = 0; j < i; ++j) {
				if(arr[i] >= arr[j]) ++cnt;
			}
			ans += cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}
