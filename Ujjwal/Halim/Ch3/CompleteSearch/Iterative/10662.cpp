#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;


int main() {
	int t, r, h;
	while (scanf("%d %d %d", &t, &r, &h) != EOF) {
		vi T(t), R(r), H(h);
		vector<vi> tr(t, vi(r)), rh(r, vi(h)), ht(h, vi(t));
		
		auto GetPrice = [&] (vi & a) {
			for(int & x : a) {
				scanf("%d", &x);
			}
		};
		
		auto GetMat = [&] (vector<vi> & b) {
			for(auto & v : b) {
				for(int & x : v) {
					scanf("%d", &x);
				}
			}
		};
		
		GetPrice(T);
		GetMat(tr);
		GetPrice(R);
		GetMat(rh);
		GetPrice(H);
		GetMat(ht);
		
		int ans = (int)1e9 + 10;
		int a, b, c;
		a = b = c =  - 1;
		for(int i = 0; i < t; ++i) {
			for(int j = 0; j < r; ++j) {
				for(int k = 0; k < t; ++k) {
					if(tr[i][j] && rh[j][k] && ht[k][i]) {
						int cost = T[i] + R[j] + H[k];
						if(cost < ans) {
							ans = cost;
							a = i, b = j, c = k;
						}
					}
				}
			}
		}
		if(ans == (int)1e9 + 10) puts("Don't get married!");
		else printf("%d %d %d:%d\n", a + 1, b + 1, c + 1, ans);
	}
	
		
	return 0;
}
