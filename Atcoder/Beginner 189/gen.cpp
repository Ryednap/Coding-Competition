#include <bits/stdc++.h>

int rand(int a, int b) {
	return rand()%(b - a + 1);
}

int main(int argv, char ** argc) {
	srand(atoi(argc[0]));
	puts("10000");
	for(int i = 0; i < 10000; ++i) {
		printf("%d ", 100);
	}
	puts("");
	return 0;
}
