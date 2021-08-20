#include <bits/stdc++.h>

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n; scanf("%d", &n);
		int ans = 0;
		for(int i = 0; i < 2 * n; ++i) {
			int x; scanf("%d", &x);
			if(x & 1) ++ans;
			else --ans;
		}
		puts(ans == 0 ? "Yes" : "No");
	}
	return 0;
}
