#include <bits/stdc++.h>

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		std::string s, t;
		std::cin >> s >> t;
		const int n = (int) s.length();
		const int m = (int) t.length();
		bool ok = true;
		for(int i = m - 1, j = n - 1; i >= 0; --i) {
			while (j >= 0 && s[j] != t[i])
				j -= 2;
			if(j < 0) {
				ok = false;
				break;
			}
			j --;
		}
		puts(ok ? "YES" : "NO");
	}
}