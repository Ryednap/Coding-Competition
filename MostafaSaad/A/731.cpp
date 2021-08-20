#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int Mod(int a) {
	return (a + 26) % 26;
}

int main() {
	std :: string s;
	cin >> s;
	int curr = 1;
	int answer = 0;
	for(char ch : s) {
		int here = (ch - 'a' + 1);
		int a = Mod(here - curr);
		int b = Mod(curr - here);
		answer += min(a, b);
		curr = here;
	}

	printf("%d\n", answer);
	return 0;
}