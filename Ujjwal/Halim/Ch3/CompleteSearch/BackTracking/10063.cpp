#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


using pii = pair<int, int>;
#define f first
#define s second

int main() {
	int n, m;
	while (scanf("%d", &n) && n) {
		scanf("%d", &m);
		pii arr[m], brr[m];
		pii left, right;
		scanf("%d %d", &left.f, &left.s);
		scanf("%d %d", &right.f, &right.s);
		
		for(int i = 0; i < m; ++i) {
			scanf("%d %d", &arr[i].f, &arr[i].s);
			brr[i] = {arr[i].s, arr[i].f};
		}
		
		auto Match = [&] (pii a, pii b) {
			return a.s == b.f;
		};
		
		bool ok = false;
		for(int i = 0; i < (1 << m); ++i) {
			if(__builtin_popcount(i) != n) continue;
			pii prev = left;
			bool here = true;
			
			for(int j = 0; j < m; ++j) {
				if(i & (1 << j)) {
					
					if(Match(prev, arr[j])) {
						prev = arr[j];
									
					} else if(Match(prev, brr[j])) {
						prev = brr[j];
						
					} else {
						here = false;
						break;
					}
				}					
			}
			
			if(!Match(prev, right)) {
					here = false;
			}
			
			if(here) {
				ok = true;
				break;
			}
		}
		puts(ok ? "YES" : "NO");
	}
			
	
	return 0;
}
