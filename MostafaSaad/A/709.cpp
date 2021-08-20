#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, b, d;
	scanf("%d %d %d", &n, &b, &d);
	int answer = 0;
	int waste = 0;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if(x <= b) waste += x;
		if(waste > d) ++answer, waste = 0;
	}
	printf("%d\n", answer);
	return 0;
}