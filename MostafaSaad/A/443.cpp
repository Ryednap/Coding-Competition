#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	std :: string s;
	getline(std :: cin , s);
	set<char> st;
	for(int i = 1; i < (int)s.length() - 1; i += 3) {
		st.insert(s[i]);
	}
	printf("%d\n", (int)st.size());
	return 0;
}