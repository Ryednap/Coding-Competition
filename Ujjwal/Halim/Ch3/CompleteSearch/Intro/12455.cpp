#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d", &qq);
	while( qq--) {
		int l, n;
		scanf("%d %d",&l, &n);
		int arr[n];
		for(int i = 0 ; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		bool ok = false;
		for(int i = 0; i < (1 << n); ++i) {
			int sum = 0;
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) sum += arr[j];
			}
			if(sum == l) {
				ok = true;
				break;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
