#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d",&n);
	int answer = 1;
	std :: string prev;
	cin >> prev;
	for(int i = 1; i < n; ++i) {
		std :: string curr;
		cin >> curr;
		if(curr[0] == prev[1])  ++answer;
		prev = curr;
	}

	printf("%d\n", answer);
	return 0;
}