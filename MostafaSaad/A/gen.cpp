#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return rand() % (b - a + 1);
}

int main(int argc, char ** argv) {
	srand(stoi(argv[1]));
	puts("1");
	return 0;
}