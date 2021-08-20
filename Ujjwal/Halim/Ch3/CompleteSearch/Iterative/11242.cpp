#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

struct Frac {
	int n, d;
	Frac () {}
	Frac (int a, int b) : n(a), d(b) {}
	bool operator < (const Frac & f) const {
		return n * f.d < d * f.n;
	}
	Frac operator / (const Frac & f) {
		return Frac(n * f.d , d * f.n);
	}
};
#ifdef LOCAL
	debug & operator << (debug & d, const Frac & f) {
		d << "( " << f.n << ", " << f.d << " )";
		return d;
	}
#endif

int main() {
	int f, r;
	while (scanf("%d",&f) && f) {
		scanf("%d", &r);
		int a[f], b[r];
		for(int i = 0; i < f; ++i) {
			scanf("%d", &a[i]);
		}
		for(int j = 0; j < r; ++j) {
			scanf("%d", &b[j]);
		}
		
		vector<Frac> ratio;
		for(int i = 0; i < f; ++i) {
			for(int j = 0; j < r; ++j) {
				ratio.push_back(Frac(b[j], a[i]));
			}
		}
		sort(ratio.begin(), ratio.end());

		double ans = 0.0;
		for(int i = 1; i < (int)ratio.size(); ++i) {
			Frac cmp = ratio[i] / ratio[i - 1];
			ans = max(ans, (double)cmp.n/ (double)cmp.d);
		}
		printf("%.2f\n", ans);
	}
	return 0;
}
