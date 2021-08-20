#include "bits/stdc++.h"

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using psi = pair<int, string>;

int main() {
	int n;
	scanf("%d", &n);
	vector<psi> v(n);
	for(auto & p : v) {
		cin >> p.s >> p.f;
	}
	sort(v.rbegin(),v.rend());
	printf("%s\n", v[1].s.c_str());
	return 0;
}
