#include <bits/stdc++.h>
using namespace std;

const int OO = (int)1e9 + 10;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		int ans = 100;
		function < int (int, int) > F = [&] (int x, int y) { // should have used this function instead of the log one doubles are always to stay away
			
			if(x == 0) return 0;
			else return F(x / y, y) + 1;
		};
		
		for(int i = 0; i <= 30; ++i) {
			if(b + i < 2) continue;
			ans = min(ans, F(a, b + i) + i);
		}
		printf("%d\n", ans);
	}
	return 0;	
}
