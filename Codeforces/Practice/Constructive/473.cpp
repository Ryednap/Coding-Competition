#include <bits/stdc++.h>
using namespace std;

// A nicee problem


int main() {
	int n;
	scanf("%d", &n);
	if(n < 6) puts("-1");
	else {
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", 1, 3);
		printf("%d %d\n", 1, 4);
		for(int i = 5; i <= 6; ++i) {
			printf("%d %d\n",2, i);
		}
	}
	
	for(int i = 1; i < n; ++i) {
		printf("%d %d\n", i , i + 1);
	}
	
	return 0;
} 
