#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
using vpi = vector<pii>;
#define f first
#define s second

int  main(int argc, char const *argv[]) {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		printf ("Case #%d: ", tt);
		int n;
		scanf ("%d", &n);
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			v[i] = i;
		}
		int total = 0, count = 0;
		do {
			count++;
			total++;
			for (int i = 1; i < n; ++i) {
				if (v[i] > v[i - 1]) 
					++count;
			}

		} while (next_permutation(v.begin(), v.end()));
		printf ("%.10f\n", (float)count / total);
	}
	return 0;
}