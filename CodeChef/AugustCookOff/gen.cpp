#include <bits/stdc++.h>

using ll = long long;
ll rand (ll a, ll b) {
	return std :: rand() % (b - a + 1);
}

int main (int argc, char ** argv) {
	srand(std :: stoi(argv[1]));
	int qq = 1;
	printf ("%d\n", qq);
	for (int _ = 0; _ < qq; ++_) {
		int n = 5000;
		printf ("%d %lld %lld\n", n, rand(1, n / 2 - 1), rand(1, 1e9));
		for (int i = 0; i < n; ++i) {
			printf ("%lld ", rand(1, 1e9));
		}
		puts("");
	}
}