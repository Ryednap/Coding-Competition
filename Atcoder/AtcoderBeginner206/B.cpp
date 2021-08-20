#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


const int NAX = 1e7;

long long F(int a) {
	return (a * (a + 1)) >> 1;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= NAX; ++i) {
		if(F(i) >= n) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}