#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif
#define len(x) ((int)(x.length()))

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		std::string s, t;
		std::cin >> s >> t;

		bool ok = false;
		for(int i = 0; i < len(s); ++i) {
			for(int right = 0; right < len(t); ++right) {
				int left = len(t) - right - 1, curr = i;
				std::string c = "";
				c += s[i];
				for(int rt = 0; rt < right; ++rt) {
					if(curr + 1 >= len(s))
						break;
					c += s[++curr];
				}
				for(int lt = 0; lt < left;  ++lt) {
					if(curr - 1 < 0)
						break;
					c += s[--curr];
				}
				//debug() << owo(c) owo(right) owo(left);
				ok |= (c == t);
			}
		}
		puts(ok ? "YES" : "NO");
	}
}
