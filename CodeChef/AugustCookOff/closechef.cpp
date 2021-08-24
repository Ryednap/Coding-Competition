#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

struct FastScanner {
	FastScanner () {}
	std :: string next () {
		std :: string s;
		std :: cin >> s;
		return s;
	}
	int nextInt () {
		int x;
		scanf ("%d", &x);
		return x;
	}
	long long  nextLong () {
		long long x;
		scanf ("%lld", &x);
		return x;
	}
	float nextFloat() {
		float x;
		scanf ("%f", &x);
		return x;
	}
};

FastScanner fs;
int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 0; tt < qq; ++tt) {
		int n = fs.nextInt();
		vector<long long> v(n);
		for (long long & x : v) {
			x = fs.nextLong();
		}
		sort (v.rbegin(), v.rend());
		if (n == 1) {
			puts("1");
			continue;
		}
		bool ok = true;
		long long a = 1ll * v[0] * v[1];
		long long b = 1ll * v[0] * v[n - 1];
		long long c = 1ll * v[n - 2] * v[n - 1];
		ok &= (find(v.begin(), v.end(), a) != v.end());
		ok &= (find(v.begin(), v.end(), b) != v.end());
		ok &= (find(v.begin(), v.end(), c) != v.end());
		puts (ok ? "1" : "0");
	}
	return 0;
}