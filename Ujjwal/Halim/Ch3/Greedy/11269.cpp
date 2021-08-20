#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

// Nice little problem involving sorting.

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<pii> arr(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i].f);
		}
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i].s);
		}
		
		sort(arr.begin(), arr.end(), [](const pii & a, const pii & b) {
			
			int costA = a.f + max(0, a.s - b.f) + b.f + b.s;
			int costB = b.f + max(0, b.s - a.f) + a.f + a.s;
			
			return costA < costB;
		});
		debug() << owo(arr);
		int cost = 0, prev = 0;
		for(int i = 0; i < n; ++i) {
			int prevCost = max(prev - arr[i].f, 0); 
			cost += arr[i].f;
			prev = arr[i].s + prevCost;
		}
		printf("%d\n", cost + prev);
	}
		
	return 0;
}
