#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d", &n);
	int answer = 0;
	for( int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a + b + c >= 2) ++answer;
	}
	printf("%d\n", answer);
	return 0;
}