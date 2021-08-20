#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		std :: string s;
		cin >> s;
		if((int)s.length() > 10) {
			printf("%c%d%c\n", s[0], (int)s.length() - 2, s.back());
		} else puts(s.c_str());
	}
	return 0;
}