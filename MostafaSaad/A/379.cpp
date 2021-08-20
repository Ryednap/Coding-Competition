#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d",&n);
	char s[n + 1];
	scanf("%s", s);
	int a = 0, d = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'A') ++a;
		else ++d;
	}

	if(a > d) puts("Anton");
	else if(d > a ) puts("Danik");
	else puts("Friendship");

	return 0;
}