#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n * 2 ^ n) complexity.
// the question has lot of misunderstanding

int main() {
	int qq;
	scanf("%d", &qq);
	while(qq--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		int total = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			total += arr[i];
		}
		
		const int half = (total >> 1) + (total & 1);	

		int count[n] = {0};
		
		for(int i = 0; i < (1 << n); ++i) {
			int power = 0;
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) {
					power += arr[j];
				}
			}
			
			for(int j = 0; j < n; ++j) {
				if(!(i & (1 << j))) {
					if(power < half && power + arr[j] >= half) count[j]++;
				}
			}
		}
		
		for(int i = 0; i < n; ++i) {
			printf("party %d has power index %d\n", i + 1, count[i]);
		}
		puts("");
		
	}
		
		
	return 0;
}
