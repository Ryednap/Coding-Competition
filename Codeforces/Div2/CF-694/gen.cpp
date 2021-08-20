#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	int x =  rand() % (b - a + 1);
	if(x == 0) x = 1;
	return x;
}

int main (int argc, char ** argv) {
	srand(stoi(argv[1]));
	puts("1");
	puts("1000 10000");
	for(int i = 0; i < 1000; ++i) {
		printf("%d ", rand(1, 10000));
	}
	puts("");
	for(int i = 0; i < 10000; ++i) {
		printf("%d ", i + 10);
	}
	puts("");
	return 0;
}
