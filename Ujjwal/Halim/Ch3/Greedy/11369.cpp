#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int qq;
	scanf("%d",&qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n);
		reverse(arr, arr + n);
		
		int cost = 0;
		for(int i = 0; i < n; i += 3) {
			if(i + 2 < n) {
				cost += arr[i + 2];
			}
		}	
		printf("%d\n", cost);
	}	
	return 0;
}
