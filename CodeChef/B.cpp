#include <bits/stdc++.h>
using namespace std;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int g, c;
		scanf("%d %d", &g, &c);
		printf("%d\n", (c * c) / (2 * g));
	}
}