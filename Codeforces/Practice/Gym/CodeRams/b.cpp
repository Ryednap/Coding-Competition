#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int arr[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n, greater<int>());
	long long ans = 0;
	for(int i = 0; i < m; ++i) {
		ans += arr[i];
	}
	--k;
	int curr = 0;
	for(int i = m; i < n && k; ++i) {
		ans += arr[i];
		++curr;
		if(curr == m - 1) {
			curr = 0;
			--k;
		}
	}
	
	
	printf("%lld\n", ans);
	return 0;
}
