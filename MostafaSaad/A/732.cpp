#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int k, r;
	scanf("%d %d", &k , &r);
	int answer = 1;
	while ((k * answer - r) % 10 != 0 && (k * answer) % 10 != 0)  ++answer;
	printf("%d\n", answer);
	return 0;
}