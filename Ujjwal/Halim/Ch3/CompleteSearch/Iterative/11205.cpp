#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;

// O(2 ^ p * n) complexity
// There was two confusion whether we need to (off -> on) or (on -> off) the correct is the second choice


int main() {
	int qq;
	scanf("%d",&qq);
	while (qq--) {
		int N, P;
		scanf("%d %d", &P, &N);
		vector<vi> v(N, vi(P));
		for(auto & ar : v) {
			for(auto & x : ar) {
				scanf("%d", &x);
			}
		}
		
		int answer = 50;
		for(int i = 0; i < (1 << P); ++i) {
			set<vi> s;
			bool ok = true;
			for(int j = 0; j < N; ++j) {
				vi ar = v[j];
				for(int k = 0 ; k < P; ++k) {
					if(ar[k] & !(i & (1 << k))) {
						ar[k] = 0;
					}
				}
				if(s.find(ar) != s.end()) ok = false;
				else s.insert(ar);
			}
			if(ok) answer = min(answer, __builtin_popcount(i));
		}
			
		printf("%d\n", answer);
	}
		
	return 0;
}
