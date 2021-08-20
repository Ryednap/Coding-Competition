#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A nice Problem why we need to add two min numbers 
// If we unfold the addition on suppose a b c d
// it's like (a + b) + (a + b + c) + (a + b + c + d)
// so it's better that a < b < c < d to make this sum less

// 4 min 16 sec to think and understand
// 4 min 41 sec to code


int main( ) {
	int n;
	while (scanf("%d", &n) && n) {
		priority_queue<long long> pq;
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			pq.push(-x);
		}
		long long ans = 0;
		while ((int)pq.size() > 1) {
			auto a = -(pq.top()); pq.pop();
			auto b = -(pq.top()); pq.pop();
			auto c = a + b;
			ans += c;
			pq.push(-c);
		}
		printf("%lld\n", ans);
	}
	
	return 0;	
}
