#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// An easy problem 
// Note that minimum of swaps is equal to the total number of inversion.

int main() {
	int n, tt = 0;
	while (scanf("%d", &n) && n) {
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		int count = 0, answer = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(arr[i] > arr[j]) ++count;
			}
		}
		
		function < void(int) > Solve = [&] (int x) {
			if(is_sorted(arr, arr + n)) {
				answer += (count == x);
				return;
			}
			
			for(int i = 1; i < n; ++i) {
				if(arr[i] < arr[i - 1]) {
					swap(arr[i], arr[i - 1]);
					Solve(x + 1);
					swap(arr[i], arr[i - 1]);
				}
			}
		};
		
		if(is_sorted(arr, arr + n)) printf("There are 0 swap maps for input data set %d.\n", ++tt);
		else {
			Solve(0);
			printf("There are %d swap maps for input data set %d.\n", answer, ++tt);
		}
	}
	
	return 0;
}
