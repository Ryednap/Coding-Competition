#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	string a, b;
	cin >> a >> b;

	std :: transform(a.begin(), a.end(), a.begin(), ::tolower);
	std :: transform(b.begin(), b.end(), b.begin(), ::tolower);

	if(a > b) puts("1");
	else if(b > a) puts("-1");
	else puts("0");

	return 0;
}