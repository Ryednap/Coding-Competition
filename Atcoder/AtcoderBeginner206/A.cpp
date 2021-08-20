#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif



int main() {
	int n;
	scanf("%d",&n);
	int value = (int)(1.08 * n);
	if(value == 206) {
		printf("so-so");
	} else if(value < 206) {
		puts("Yay!");
	} else {
		puts(":(");
	}
	return 0;
}