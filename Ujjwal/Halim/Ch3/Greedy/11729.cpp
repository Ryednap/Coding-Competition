#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

int main() {
	int tt = 0, n;
	while (scanf("%d", &n) && n) {
		printf("Case %d: ", ++tt);
		pii arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &arr[i].f, &arr[i].s);
		}
		
		sort(arr, arr + n, [] (const pii & a, const pii & b) {
			int costA = a.f + a.s + max(0, b.f + b.s - a.s);
			int costB = b.f + b.s + max(0, a.f + a.s - b.s);
			
			return costA < costB;
		});
		
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			ans += arr[i].f;
		}
		
		int delta = 0, sum = 0;
		for(int i = 0; i < n; ++i) {
			sum += arr[i].f;
			delta = max(delta, max(0, sum + arr[i].s - ans));
		} 
		
		printf("%d\n", ans + delta);
	}
		
	return 0;
}
