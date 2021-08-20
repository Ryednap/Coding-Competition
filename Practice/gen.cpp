#include <bits/stdc++.h>

int rand(int a, int b) {
	return rand() % (b - a + 1);
}

int main(int argc, char ** argv) {
	srand(atoi(argv[1]));
	int qq = rand(1, 1);
	printf("%d\n", qq);
	int n = rand(1, 20);
	printf("%d\n", n);
	int arr[n];
	for(int i = 0; i < n; ++i) {
		arr[i] = i + 1;
	}
	std::random_shuffle(arr, arr + n);
	for(int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	puts("");
	puts("");
	return 0;
}