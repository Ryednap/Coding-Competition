#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
	return rand() % (b - a) + 2;
}

int main(int argv, char ** argc) {
	srand(stoi(argc[1]));
	int n;
	n = rand(4, 22);
	printf("%d\n", n);
	for(int i = 0; i < n; ++i) {
		if(i == 4 || i == 5 || i == 6) printf("%d ", 1);
		else printf("0 ");
	}
	puts("");
	return 0;
}
