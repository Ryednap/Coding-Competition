#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A much better implementation
// Here whenever we encounter a . it's better to make the next cell as scarecrow so that [i, i + 1, i + 2] are done so start from i + 3 next
// That's so simple.

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		char str[n + 1];
		scanf("%s", str);
		
		int ans = 0;
		for(int i = 0; i < n; ) {
			if(str[i] == '.') {
				++ans;
				i += 3;
				
			} else ++i;
		}
		
		printf("Case %d: %d\n", ++tt, ans);
	}	
	return 0;
}
