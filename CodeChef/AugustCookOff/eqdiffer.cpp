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
		int n = fs. nextInt();
		unordered_map<int, int> mapper;
		for (int i = 0; i < n; ++i) {
			int x = fs.nextInt();
			mapper[x]++;
		}
		int ans = 0;
		for (auto p : mapper) {
			ans = std :: max(ans, p.second);
		}
		ans = n - ans;
		if (n == 1)
			ans = 0;
		else if(ans == n - 1) 
			ans = n - 2;
		printf ("%d\n", ans);
	}
	return 0;
}