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
	int s, t;
	scanf ("%d %d", &s, &t);
	int ans = 0;
	for (int i = 0; i < nax; ++i) {
		for (int j = 0; j < nax; ++j) {
			for (int k = 0; k < nax; ++k) {
				if (i + j + k <= s && i * j * k <= t) {
					++ans;
				}
			}
		}
	}
	printf ("%d\n", ans);
	return 0;
}