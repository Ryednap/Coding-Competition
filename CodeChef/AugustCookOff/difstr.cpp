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
		vector<string> v(n);
		for (string & s : v) {
			s = fs.next();
		}
		string ans(n, '0');
		for (int i = 0; i < 128; ++i) {
			for (int j = 0; j < 7; ++j) {
				if (i & (1 << j))
					ans[j] = '1';
			}
			if (find(v.begin(), v.end(), ans) == v.end()) {
				break;
			} else ans = string(n, '0');
		}
		puts(ans.c_str());
	}
	return 0;
}