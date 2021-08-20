#include <bits/stdc++.h>
using namespace std;

int main() {
	int qq;
	scanf("%d", &qq);
	while(qq -- ) {
		int n;
		scanf("%d",&n);
		if(n == 1) printf("9");
		else if(n == 2) printf("98");
		else {
			int prev = 8;
			printf("98");
			for(int i = 0; i < n - 2; ++i) {
				prev = (prev + 1)%10;
				printf("%d", prev);
			}
		}
		puts("");
	}
	return 0;
}
				
