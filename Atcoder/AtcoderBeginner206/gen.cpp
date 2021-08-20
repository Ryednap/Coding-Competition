#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
	return rand() % (b - a + 1);
}

int main(int argc, char **argv) {
	srand(atoi(argv[1]));

	int n = rand(1, 20);
	printf("%d\n", n);
	for(int i = 0; i < n; ++i) {
		printf("%d ", rand(1, 50));
	}
	puts("");
	return 0;
}