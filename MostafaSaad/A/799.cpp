#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, t, k, d;
	scanf("%d %d %d %d", &n, &t, &k ,&d);
	int original = (n + k - 1) / k * t;
	
	puts(original > t + d ? "YES" : "NO");
	return 0;
}