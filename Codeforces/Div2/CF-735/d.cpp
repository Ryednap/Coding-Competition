#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;

#define f first
#define s second



int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		if(n == 1){
			puts("a");
			continue;
		}
		auto printChar = [&] (char ch, int x) {
			if(x <= 0) return;
			string str(x, ch);
			cout << str;
		};

		if(n & 1) {
			n -= 2;
			printChar('a', (n + 1) >> 1);
			printChar('b', 1);
			printChar('a', n - ((n + 1) >> 1));
			printChar('c', 1);

		} else {
			n -= 1;
			printChar('a', (n + 1) >> 1);
			printChar('b', 1);
			printChar('a', n  - ((n + 1) >> 1));
		}
		puts("");
	}
	return 0;
}