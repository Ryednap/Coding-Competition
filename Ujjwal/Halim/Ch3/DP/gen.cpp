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


int main(int argc, char ** argv) {
	srand(atoi(argv[1]));
	
	puts("1");
	int n = rand(1, 10);
	printf("%d\n",n );
	for(int i = 0; i < n; ++i) {
		printf("%d\n", rand(1, 1000));
	}
	puts("");
	return 0;
	
}
