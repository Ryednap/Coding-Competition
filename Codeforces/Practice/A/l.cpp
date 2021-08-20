#include <bits/stdc++.h>
using namespace std;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int H[n + 1];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &H[i]);
		}
		H[n] = 0;
		int ans = -1;
		while(k) {
			int curr = -1;
			for(int i = 0; i < n; ++i) {
				if(H[i] >= H[i + 1]) continue;
				else {
					H[i]++;
					curr = i;
					--k;
					break;
				}
			}
			if(k == 0) {
				ans = curr + 1;
				break;
				
			} else if(curr == -1) {
				ans = -1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;	
}
