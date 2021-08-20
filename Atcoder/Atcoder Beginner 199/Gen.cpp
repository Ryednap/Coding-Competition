#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int rand(int a, int b) {
	return rand() % (b - a + 1);
}

int main(int argv, char ** argc) {
	srand(atoi(argc[1]));
	int n = rand(1, 18);
	int m = rand(1, 100);
	
	printf("%d %d\n", n, m);
	for(int i = 0; i < m; ++i) {
		printf("%d %d %d\n", rand(1, n - 1), rand(1, n - 1), rand(0, n - 1));
	}
	puts("");		
	return 0;
}
