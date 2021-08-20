#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define mp(a, x) make_pair(a, x);
#define sz(x) ((int)x.size())

int main () {
	int n;
	scanf ("%d", &n);
	vector<pii> a(n);
	for (int i = 0; i < n;++i){
		scanf ("%d",&a[i].f);
		a[i].s = i;
	}
	sort (a.begin(), a.end());
	printf ("%d\n", a[n - 2].s + 1);
	return 0;
}