#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int d, x, y, z;
		scanf("%d %d %d %d", &d, &x, &y, &z);
		int a = 7 * x;
		int b = d * y + (7 - d) * z;
		printf("%d\n", std :: max(a, b));
	}
	return 0;
}