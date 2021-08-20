#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL 
#include "uj.h"
#endif 

using pii = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pii>;

#define f first
#define s second
#define sz(x) ((int)x.size())


int main() {
	int n, a, x, y;
	scanf("%d %d %d %d", &n, &a, &x, &y);
	int cost = 0;
	if(n > a) {
		cost+= a * x;
		n -= a;
		cost += n * y;
	} else cost += n * x;
	printf("%d\n", cost);

	return 0;
}