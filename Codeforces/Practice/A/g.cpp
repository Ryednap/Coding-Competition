#include <bits/stdc++.h>
using namespace std;

// 6 min

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int l, r;
		scanf("%d %d", &l, &r);
		if(r < 2 * l) puts("-1 -1");
		else printf("%d %d\n", l, 2 * l);
	}
	return 0;	
}
