#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
	return rand() % (b - a + 1);
}

int main() {
	int n = 1e7;
	printf("%d %d\n", n, (int)1e5);
	for(int i = 0; i < (int)1e5; ++i) {
		int l = rand(1, n);
		int m = min(l + rand(1, n), n);
		
		printf("%d %d %d\n", l, m, rand(1, 1e9));
	}
	return 0;
}		
