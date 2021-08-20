#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int c, s, tt = 0;
	while (scanf("%d %d", &c, &s) != EOF) {
		double avg = 0;
		vector<int> v;
		if(s < 2 * c) {
			for(int i = 0; i < 2 * c - s; ++i) {
				v.push_back(0);
			}
		}
		
		for(int i = 0; i < s; ++i) {
			int x; scanf("%d", &x);
			v.push_back(x);
			avg += x;
		}
		avg /= c;
		sort(v.begin(), v.end());
		//debug() << owo(v);
		
		int C[c] = {0};
		vector<vector<int>> store(c);
		for(int i = 0, k = 0, j = (int)v.size() -1 ; i <= j; ++i, --j, k = (k + 1)%c) {
			if(i == j) {
				C[k] = v[i];
				if(v[i]) store[k].push_back(v[i]);
					
			} else {
				if(v[i]) store[k].push_back(v[i]);
				if(v[j]) store[k].push_back(v[j]);
				C[k] = v[i] + v[j];
			}
		}
		sort(store.begin(), store.end());
		//debug() << owo(store);
		double ans = 0;
		printf("Set #%d\n", ++tt);
		for(int i = 0; i < c; ++i) {
			printf("%2d:", i);
			for(auto x : store[i]) {
				if(x) printf(" %d", x);
			}
			puts("");
			ans += fabs(avg - C[i]);
		}
		printf("IMBALANCE = %.5f\n", ans);
		puts("");
	}
	return 0;
}
