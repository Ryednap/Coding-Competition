#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		int left = y - 1;
		int right = arr[x - 1] - y;
		if(x != 1) arr[x - 2] += left;
		if(x != n) arr[x] += right;
		arr[x - 1] = 0;
	}

	for(int i = 0; i < n; ++i) {
		printf("%d\n", arr[i]);
	}
	return 0;
}