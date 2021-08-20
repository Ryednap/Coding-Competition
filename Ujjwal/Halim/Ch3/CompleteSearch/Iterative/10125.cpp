#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<long long, long long>;
#define f first
#define s second

const long long OO = (int)1e18;

// O(n ^ 2) complexity with some log factor per test case
// Reform the problem as a + b = d - c

int main() {
	int n;
	while (scanf("%d",&n) && n) {
		long long arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%lld",&arr[i]);
		}
		sort(arr, arr + n);
		map<long long, vector<pii>> m;
		
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				long long sum = arr[i] + arr[j];
				m[sum].push_back( {arr[i], arr[j]} );
			}
		}
		
		long long answer = -OO;
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				long long x = arr[j] - arr[i];
				if(m.find(x) != m.end()) {
	
					for(auto p : m[x]) {
						if(p.f != arr[i] && p.s != arr[j]) { // note that pair itself is sorted so we avoided 4 comparisons
							answer = max(answer, arr[j]);
							break;
						}
					}
					
				}
			}
		}
		if(answer == -OO) puts("no solution");
		else printf("%lld\n", answer);
	}
	return 0;
}
