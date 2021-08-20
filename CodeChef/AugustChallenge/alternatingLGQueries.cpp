#include <bits/stdc++.h>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)


void solve() {
	std::array<int, 2> ans = {0};
	for (int i = 0; i < 2; ++i) {
		int a, b, c;
		scanf ("%d %d %d", &a, &b, &c);
		ans[i] = a + b + c;
	}
	if (ans[0] > ans[1])
		puts("1");
	else puts("0");
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		solve();
	}
	return 0;
}