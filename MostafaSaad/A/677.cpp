#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, h;
	scanf("%d %d", &n, &h);
	int answer = 0;
	for( int i = 0; i < n; ++i) {
		int x ;
		scanf("%d", &x);
		answer += x > h ? 2 : 1;
	}
	printf("%d\n", answer);
	return 0;
}