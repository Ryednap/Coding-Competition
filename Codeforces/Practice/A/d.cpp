#include <bits/stdc++.h>
using namespace std;

// 3 min

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		int maxi = 0, mini = (int)1e9 + 10;
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d",&x);
			maxi = max(x, maxi);
			mini = min(x, mini);
		}
		printf("%d\n", maxi == mini ? n : 1);
	}
	return 0;	
}
