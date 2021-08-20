#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	int answer = 1;
	for(int i = 1; i < n; ++i) {
		if(s[i] != s[i - 1]) ++answer;
	}
	printf("%d\n", n - answer);
	return 0;
}