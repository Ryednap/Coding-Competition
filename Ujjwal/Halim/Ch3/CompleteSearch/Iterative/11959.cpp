#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second
#define mp make_pair

std :: string build (unsigned char a, unsigned char b) {
	std :: string p = ""; p += a; p += b;
	std :: string q = ""; q += b; q += a;
	return std :: min(p, q);
}

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		string a, b;
		cin >> a >> b;
		pii m [] = {{0, 1}, {2, 4}, {3, 5}};
		vector<string> x, y;
		for(int i = 0; i < 3; ++i) {
			string first = build(a[m[i].f], a[m[i].s]);
			string second = build(b[m[i].f], b[m[i].s]);

			x.push_back(first);
			y.push_back(second);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		//debug() << owo(x) owo(y);
		puts(x == y ? "Equal" : "Not Equal");
	}
	return 0;
}
