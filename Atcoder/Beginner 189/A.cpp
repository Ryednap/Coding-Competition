#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif



int main() {
	char s[10];
	scanf("%s",s);
	if(s[0] == s[1] && s[0] == s[2]) {
		puts("Won");
	} else puts("Lost");
	return 0;
}
