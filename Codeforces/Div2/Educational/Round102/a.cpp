#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int qq;
	scanf("%d", &qq);
	while(qq--) {
		int n, d;
		scanf("%d %d", &n, &d);
		int arr[n];
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			ok &= arr[i] <= d;
		}
		sort(arr, arr + n);
		if(ok) puts("YES");
		else if(arr[0] + arr[1] <= d) puts("YES");
		else puts("NO");
	}
	
	return 0;	
}
