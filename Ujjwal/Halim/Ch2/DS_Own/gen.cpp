#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
	return rand() % (b - a + 1);
}

int main(int argc, char ** argv) {
	srand(atoi(argv[1]));
	int n = 1e6;
	int q = 1e6;
	puts("1");
	printf("%d %d\n",n, q);
	for(int i = 0; i < n; ++i) {
		printf("%d ", i + 1);
	}
	puts("");
	while( q -- ) {
		int l = rand(1, 1000);
		int r = l + rand(1, 12132);
		printf("%d %d\n", l, r);
	}
	puts("");
	return 0;
}	
	
