#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		map<pii, int> mapper;
		for(int i = 0 ; i < n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			mapper[{a, b}]++;
		}
		
		bool ok = true;
		for(pair<const pii, int> & p : mapper) {
			const pii q = {p.f.s, p.f.f};
			if(p.s != mapper[q]) {
				ok = false;
				break;
			} else {
				p.s = 0;
				mapper[q] = 0;
			}
		}
		
		puts(ok ? "YES" : "NO");
	}
		
	return 0;
}
