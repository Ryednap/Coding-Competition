#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

void Solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0, j = n - 1; i < j; ++i,--j) {
		if(s[i] != s[j]) {
			++cnt;
		}
	}
	
	printf("%d\n", (int)abs(cnt - k));
}


int main() {
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i) {
		printf("Case #%d: ", i + 1);
		Solve();
	}
	return 0;
}


int main () {
	return 0;
}