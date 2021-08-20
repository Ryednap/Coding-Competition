#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	string s, t;
	while (cin >> s >> t) {
		const int n = (int)s.length();
		const int m = (int)t.length();
		
		bool ok = false;
		for(int i = 0, j = 0; i < m; ++i) {
			if(t[i] == s[j]) ++j;
			if(j == n) {
				ok = true;
				break;
			}
		}	
		puts(ok ? "Yes" : "No");
	}
	return 0;
}
