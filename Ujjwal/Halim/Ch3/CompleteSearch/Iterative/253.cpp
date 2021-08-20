#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

std :: string build (unsigned char a, unsigned char b ) {
	string p = ""; p += a; p += b;
	string q = ""; q += b; q += a;
	return std :: min(p, q);
}

int main() {
	string str;
	while (cin >> str) {
		string a, b;
		for(int i = 0; i < 12; ++i) {
			if(i < 6) a += str[i];
			else b += str[i];
		}
		pii m [] = {{0, 5}, {1, 4}, {2, 3}};
		vector<string> x, y;
		for(int i = 0; i < 3; ++i) {
			string first = build(a[m[i].f], a[m[i].s]);
			string second = build(b[m[i].f], b[m[i].s]);

			x.push_back(first);
			y.push_back(second);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		puts(x == y ? "TRUE" : "FALSE");
	}
	return 0;
}
