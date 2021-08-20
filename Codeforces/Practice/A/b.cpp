#include <bits/stdc++.h>
using namespace std;

// A nice problem the statement is little shitty.
// Think how many steps it takes to reach the center
// Time :- 13 min level 800

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", (n >> 1) + 1);
	}
	return 0;	
}
