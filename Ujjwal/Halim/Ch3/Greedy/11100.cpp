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
		map<int, int> mapper;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			mapper[x]++;
		}
		
		vector<pii> a(mapper.begin(), mapper.end());
		set<pii> rem;
		for(int i = 1; i < (int)a.size(); ++i) {
			 int x = std::min(a[i - 1].s, a[i].s);
			 a[i - 1].s -= x;
			 
		}
	}
		
		
	return 0;
}
