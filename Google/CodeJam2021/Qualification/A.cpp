#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n ^ 2) algorithm


void Solve() {
	int n;
	scanf("%d", &n);
	vector<int> arr(n);
	for(int & x : arr) {
		scanf("%d", &x);
	}
	
	int ans = 0;
	for(auto itr = arr.begin(); itr != arr.end() - 1; ++itr) {
		auto j = min_element(itr, arr.end());
		ans += (int)(j - itr + 1);
		reverse(itr, j + 1);
		//debug() << owo(arr);
	}
	printf("%d\n", ans);
}

int main() {
	int qq;
	scanf("%d", &qq);
	for(int i = 1; i <= qq; ++i) {
		printf("Case #%d: ", i);
		Solve();
	}
	
	return 0;
}
	
