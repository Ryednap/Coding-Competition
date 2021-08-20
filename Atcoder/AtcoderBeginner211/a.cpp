#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pii>;

#define f first
#define s second

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	float c = (a - b) / 3.0  + b;
	printf("%.10f\n", c);
	return 0;
}