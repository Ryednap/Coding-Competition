#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	std :: string s;
	cin >> s;
	int lower = 0, upper = 0;
	for(char ch : s) {
		if(isupper(ch)) ++upper;
		else ++lower;
	}

	if(lower >= upper) std :: transform(s.begin(), s.end(), s.begin(), ::tolower);
	else std :: transform(s.begin(), s.end(), s.begin(), ::toupper);
	puts(s.c_str());
	return 0;
}