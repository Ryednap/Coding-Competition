#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int OO = (int)2e9;

int main() {
	int n;
	scanf("%d", &n);
	int A = 0, B = OO;
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		A = max(A, x);
	}
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		B = min(B, x);
	}
	
	int answer = max(0, B - A + 1);
	printf("%d\n", answer);
	return 0;
}
