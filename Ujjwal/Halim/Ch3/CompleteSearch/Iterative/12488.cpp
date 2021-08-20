#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n^2) complexity

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < n; ++i) {
			scanf("%d",&b[i]);
		}
		int answer = 0;
		for(int i = 0; i < n; ++i) {
			auto itr = find(a.begin(), a.end(), b[i]);
			assert(itr != a.end());
			int j = itr - a.begin();
			int value = *itr;
			answer += (j - i); assert(j >= i);
			a.erase(itr);
			a.insert(a.begin(), value);
		}
		printf("%d\n", answer);
	}
			
			
	return 0;
}
