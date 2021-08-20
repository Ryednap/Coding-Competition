#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
   return rand() % (b - a + 1);
}

int main (int argc , char ** argv) {
    srand(atoi(argv[1]));
    puts("20");
    int q = 20;
    while (q--) {
		int n = 100000;
		printf("%d\n", n);
		for(int i = 0; i < n;  ++i) {
			printf("%d ", rand(1, 100000));
		}
		puts("");
		int qq = 100000;
		printf("%d\n", qq);
		for(int i = 0; i < qq; ++i) {
			int l = rand(1, n);
			int r = rand(l, n);
			printf("%d %d\n", l, r);
		}
		puts("");
	}
    return 0;
}
