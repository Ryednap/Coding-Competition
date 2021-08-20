#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		string s;
		cin >> s;
		int maxi = 1;
		for(char ch : s) {
			maxi = max(maxi , ch - '0');
		}
		printf("%d\n", maxi);
	}
	return 0;
}