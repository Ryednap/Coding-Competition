#include <bits/stdc++.h>

using pi = std :: pair<int, long long>;
using vpi = std :: vector<pi>;
const long long OO = (int)1e18;


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, k;
		scanf("%d %d", &n, &k);
		vpi arr(n, pi(-1, OO));
		int temp[k];
		for(int i = 0; i < k; ++i) {
			scanf("%d", &temp[i]);
			temp[i]--;
		}
		for(int i = 0; i < k; ++i) {
			int t; scanf("%d", &t);
			arr[temp[i]] = pi(temp[i], t);
		}

		long long curr = OO;
		for(int i = 0; i < n; ++i) {
			curr++;
			if(arr[i].first != -1) {
				curr = std :: min(curr, arr[i].second);
			}
			arr[i].second = std :: min(curr, arr[i].second);
		}

		for(int i = n - 1; i >= 0; --i) {
			curr++;
			if(arr[i].first != -1) {
				curr = std :: min(curr, arr[i].second);
			}
			arr[i].second = std :: min(curr, arr[i].second);
		}

		for(int i = 0; i < n; ++i) {
			printf("%lld ", arr[i].second);
		}
		puts("");
	}
	return 0;
}