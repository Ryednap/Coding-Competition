#include <bits/stdc++.h>
using namespace std;

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using vpi = std::vector<pii>;
using vvpi = std::vector<vpi>;


#define f first
#define s second
#define len length()

const int nax = 110;

int main () {
	int n;
	scanf ("%d", &n);
	vi s(n), t(n);
	for (int & x : s) {
		scanf ("%d",&x);
	}
	for (int & x : t) {
		scanf ("%d", &x);
	}

	int pos = min_element(t.begin(), t.end()) - t.begin();
	int currMin = t[pos];
	vi ans(n);
	ans[pos] = currMin;
	for (int i = (pos + 1) % n, j = 0; j < n; j++, i = (i + 1) % n) {
		int p = (i - 1 + n) % n;
		currMin = min(currMin + s[p], t[i]);
		ans[i] = currMin;
	}

	for (int & x : ans) {
		printf ("%d\n", x);
	}
	return 0;
}