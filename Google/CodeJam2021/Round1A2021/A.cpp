#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

string inc(string a) {
	for(int i = (int)a.length() - 1; i >= 0; --i) {
		if(a[i] != '9') {
			a[i]++;
			return a;
		}
		a[i] = 0;
	}
	return '1' + a;
}

bool is_pref(string  a, string  b) {
	const int n = (int)a.length();
	const int m = (int)b.length();

	return (m >= n && b.substr(0, n) == a);
}

void Solve() {
	int N;
	scanf("%d", &N);
	string prev, next;
	cin >> prev;
	int answer = 0;
	for(int i = 1; i < N; ++i) {
		cin >> next;
		int pastLength = next.length();
		if(is_pref(next, prev)) {
			if(is_pref(next, inc(prev))) {
				next = inc(prev);

			} else {
				while ((int)next.length() <= (int)prev.length()) {
				
					next += '0';
				}
			}
		} else {
			while (next.length() < prev.length() || (next.length() == prev.length() && next <= prev)) {
				next += '0';
			}
		}
		answer += next.length() - pastLength;
		prev = next;
		/* debug() << owo(prev); */
	}

	printf("%lld\n", answer);
}

int main() {
	int qq;
	scanf("%d", &qq);
	for(int tt = 0; tt < qq; ++tt) {
		printf("Case #%d: ", tt + 1);
		Solve();
	}
	return 0;
}
