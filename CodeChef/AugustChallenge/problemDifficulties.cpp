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
	std::array<int, 4> ar;
	std::array<int, 4> done = {0};
	for (int i = 0; i < 4; ++i) {
		scanf ("%d", &ar[i]);
	}
	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		if (done[i]) continue;
		for (int j = 0; j < 4; ++j) {
			if (ar[j] == ar[i] || done[j]) continue;
			done[j] = true;
			++ans;
			break;
		}
		done[i] = true;
	}
	printf ("%d\n", ans);
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		solve();
	}
	return 0;
}