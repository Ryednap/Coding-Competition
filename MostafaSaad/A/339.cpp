#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	std :: string s;
	cin >> s;
	vector<int> v;
	for(int i = 0; i < (int)s.length(); i += 2) {
		v.push_back(s[i] - '0');
	}
	sort(v.begin(), v.end());
	printf("%d", v[0]);
	for(int i = 1; i < (int)v.size(); ++i ) {
		printf("+%d", v[i]);
	}
	puts("");
	return 0;
}