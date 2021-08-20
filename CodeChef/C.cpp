#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d %d", &n, &k);
		std :: array<int, 32> ar = {0};
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			for(int j = 0; j < 31; ++j) {
				if(x & (1 << j)) ar[j]++;
			}
		}

		int answer = 0;
		for(int i = 0; i < 32; ++i) {
			answer += (ar[i] + k - 1) / k;
		}
		printf("%d\n", answer);
	}
	return 0;
}