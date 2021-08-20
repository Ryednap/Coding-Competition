#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int OO = (int)2e9 +10;
using pii = pair<int, int>;
#define f first
#define s second

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq -- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		string st ;  cin >> st;
		vector<vector<pii>> Q(n + 1);
		for(int i = 0 ; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			Q[a].push_back( {b, i} );
		}
		
		int val[n + 1] = {0};
		for(int i = 1; i <= n; ++i) {
			val[i] = val[i - 1] + (st[i - 1] == '+' ? +1 : -1);
		}
		pii suf[n + 2];
		suf[n + 1] = make_pair(OO, -OO);
		for(int i = n; i >= 0; --i) {
			suf[i].f = min(suf[i + 1].f , val[i]);
			suf[i].s = max(suf[i + 1].s, val[i]);
		}
		
		
		
		int ans[m];
		int lo = 0, hi = 0, tot = 0;
		for(int i = 1; i <= n; ++i) {
			for(auto p : Q[i]) {
				
				function < int (int, int) > Solve = [&] (int l, int r) {
					//debug() << owo(p) owo(l) owo(r);
					assert(r >= l);
					return r - l + 1;
				};
				
				int r = p.f + 1;
				if(r > n) ans[p.s] = Solve(lo, hi);
				else {
					int x = val[r - 1];
					int a = suf[r].f + tot - x, b = suf[r].s + tot - x;
					//debug() << owo(tot) owo(x) owo(a) owo(b) owo(suf[r]);
					ans[p.s] = Solve(min(lo, a), max(hi, b));
				}
			}
			tot += (st[i - 1] == '+' ? 1 : -1);
			lo = min(lo, tot);
			hi = max(hi, tot);
		}
					
		
		for(int i = 0; i < m; ++i) {
			printf("%d\n", ans[i]);
		}
		
	}
	return 0;	
}
