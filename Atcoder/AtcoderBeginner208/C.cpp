#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;

int main() {
	int n;
	long long k;
	scanf("%d %lld", &n, &k);
	vector<pii> arr;
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		arr.emplace_back(x, i);
	}
	sort(arr.begin(), arr.end());

	vector<long long> answer(n, 0);
	long long common = k / n;
	long long rem = k % n;
	for(int i = rem - 1; i >= 0; --i) {
		answer[arr[i].second]++;
	}

	debug() << owo(arr);
	for(int i = 0; i < n; ++i) {
		printf("%lld\n", answer[i] + common);
	} 
	return 0;
}