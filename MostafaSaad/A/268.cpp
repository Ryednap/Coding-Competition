#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int n;
	scanf("%d", &n);
	int arr[n][2];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}

	int answer = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i != j && arr[j][0] == arr[i][1]) {
				++answer;
			}
		}
	}
	printf("%d\n", answer);

	return 0;
}

