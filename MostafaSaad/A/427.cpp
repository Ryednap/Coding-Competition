#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d", &n);
	int answer = 0;
	int crime = 0;
	for( int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		crime += x;
		if(crime < 0) ++answer, crime = 0;
	}
	printf("%d\n", answer);
	return 0;
}