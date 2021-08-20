#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpi = vector<pii>;
using vvpi = vector<vpi>;

#define f first
#define s second

void solve () {
	int n, k;
	scanf ("%d %d", &n, &k);
	vpi ar(k);
	vi done(2 * n);
	for (int i = 0; i < k; ++i) {
		scanf ("%d %d", &ar[i].f, &ar[i].s);
		--ar[i].f, --ar[i].s;
		done[ar[i].f] = done[ar[i].s] = true;
	}
	int ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (done[i])
			continue;
		done[i] = true;
		int maxi = -1, where = -1;
		for (int j = 0; j < 2 * n; ++j) {
			if (done[j])
				continue;
			for (int k = 0; k < 2 * n; ++k)
		}
	}
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 0; tt < qq; ++tt) {
		solve ();
	}
	return 0;
}