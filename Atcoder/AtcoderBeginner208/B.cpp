#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int fact(int a ){
	return a <= 1 ? 1 : a * fact(a - 1);
}

int main() {
	int p;
	scanf("%d", &p);
	vector<int> arr;
	for(int i = 1; i <= 10; ++i) {
		arr.push_back(fact(i));
	}

	int answer = 0;
	while (p) {
		for(int i = 9; i >= 0; --i) {
			if(p >= arr[i]) {
				p -= arr[i];
				break;
			}
		}
		++answer;
	}

	printf("%d\n",answer );

	return 0;
}