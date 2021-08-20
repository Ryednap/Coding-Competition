#include <bits/stdc++.h>
using namespace std;

// 9 min

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		int eight = (n + 3) >> 2;
		int nine = n - eight;
		for(int i =  0; i < nine; ++i) {
			printf("9");
		}
		for(int i = 0; i < eight; ++i) {
			printf("8");
		}
		puts("");
	}
	return 0;	
}
