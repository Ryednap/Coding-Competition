#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d", &n);
	deque < int>  q;
	for(int i = 0; i < n; ++i) {
		int x; 
		scanf("%d",&x);
		q.push_back(x);
	}

	int a[2] = {0, 0}, i = 0;
	while (!q.empty()) {
		if(q.front() > q.back()) {
			a[i] += q.front();
			q.pop_front();
		} else {
			a[i] += q.back();
			q.pop_back();
		}
		i = i ^ 1;
	}

	printf("%d %d\n", a[0], a[1]);

	return 0;
}