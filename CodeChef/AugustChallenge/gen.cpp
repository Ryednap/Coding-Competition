#include <bits/stdc++.h>
using namespace std;

int rand (int a, int b) {
	return rand () % (b - a + 1) + 1;
}

int main (int argc, char ** argv) {
	srand (atoi(argv[1]));
	int tt = rand (1, 100);
	printf ("%d\n", tt);
	for (int ii = 0; ii < tt; ++ii) {
		int n = rand(1, 2000);
		int m = rand(1, 1000);
		printf ("%d %d\n", n, m);
		for (int i = 0; i < m; ++i) {
			int a = rand(1, 10000);
			int b = rand(1, 10000);
			assert (b != 0);
			printf ("%d %d\n", a, b);
		}
	}
	puts("");
}