#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int n = 5;
int main() {
	int answer = 0;
	for( int i = 0; i < n; ++i) {
		for( int j = 0 ; j < n; ++j) {
			int x; 
			scanf("%d", &x);
			if(x == 1) {
				answer  += abs(i - 2) + abs(j - 2);
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}