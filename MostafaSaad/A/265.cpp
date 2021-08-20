#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	std :: string s, t;
	cin >> s >> t;
	int curr = 1;
	for(auto ch : t) {
		if(ch == s[curr - 1]) ++curr;
	}
	printf("%d\n", curr);
	return 0;
}