#include <bits/stdc++.h>

using namespace std;

// O(n) complexity based on two pointer technique. also can be done by binary search.

int main() {
	int y;
	while (scanf("%d", &y) != EOF) {
		int n; scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		int answer = -1;
		int first = -1, second = -1;
		sort(arr, arr + n);
		for(int i = 0, j = 0; i < n; ++i) {
				while (j < n && arr[j] - arr[i] + 1 <= y) {
					++j;
				}
				if(answer < (j - i)) {
					answer = j - i;
					first = i;
					second = j - 1;
				}
		}
				
		
		printf("%d %d %d\n", answer, arr[first], arr[second]);
	}
			
	return 0;
}
