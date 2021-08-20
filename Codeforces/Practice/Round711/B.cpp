#include <bits/stdc++.h>

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1) {
			puts("Yes");
			continue;
		}
		
		long long x = b;
		while (x * b <= a && b != 1) {
			x *= b;
		}
		printf("%lld %lld %lld\n", x, a - x, (a - x) % b);
		if((a - x) % b == 0) puts("Yes");
		else puts("No");
	}
	return 0;
}