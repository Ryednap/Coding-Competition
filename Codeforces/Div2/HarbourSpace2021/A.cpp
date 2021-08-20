#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define sz(x) ((int)x.size())
#define all(x) ((x.begin(), x.end()))
#define f first
#define s second



int main() {
	int qq;
	scanf("%d",&qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		++n;
		n /= 10;
		printf("%d\n", n);
	}
	return 0;
}