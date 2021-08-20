#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	std :: string s;
	cin >> s;
	set<int> st(s.begin(), s.end());
	if(size(st) & 1) puts("IGNORE HIM!");
	else puts("CHAT WITH HER!");
	return 0;
}