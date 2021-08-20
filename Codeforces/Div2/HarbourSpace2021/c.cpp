#include <bits/stdc++.h>

char s[11];
using ar = std::array<int, 2>;

int solve(int i, ar a) {
	if(a[0] > a[1] + (5 - i / 2))
		return i;
	if(a[1] > a[0] + (5 - i / 2 - (i & 1)))
		return i;

	if(i == 10){
		//puts("hi");
		return i;
	}

	if(s[i] == '0') {
		return solve(i + 1, a);
	}
	if(s[i] == '1') {
		a[i & 1]++;
		return solve(i + 1, a);
	}

	int x = solve(i + 1, a);
	a[i & 1]++;
	x = std::min(x, solve(i + 1, a));
	return x;
}

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		scanf("%s", s);
		ar a = {0, 0};
		printf("%d\n", solve(0, a));
	}
}