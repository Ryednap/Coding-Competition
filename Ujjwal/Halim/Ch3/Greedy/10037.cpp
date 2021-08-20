#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define  f first
#define s second



int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		vector<int> a, b;
		for(int i = 0 ; i < n; ++i) {
			int x; scanf("%d", &x);
			a.push_back(x);
		}
		sort(a.rbegin(), a.rend());
		
		if(n == 1) {
			printf("%d\n%d\n", a[0], a[0]);
			if(qq) puts("");
			continue;
		}
		
		int total = 0 ;
		vector<pii> ans;
		b.push_back((int)1e9);
		
		while(true) {
			 int mini = *min_element(b.begin(), b.end());
			 int sum = accumulate(a.begin(), a.end(), 0);
			 pii bestPair = {-1, -1};
			 int bestTime = (int)1e9;
			 for(int i = 0; i < (int)a.size() - 1; ++i) {
				 int cost = sum - a[i] + 2 * min(mini, a[i]);
				 if(cost < bestTime) {
					 bestPair = make_pair(a[i], a[i + 1]);
					 bestTime = cost;
					 
				 }
			 }
			 
			 total += max(bestPair.f, bestPair.s);
			 ans.push_back(bestPair);
			 b.push_back(bestPair.f);
			 b.push_back(bestPair.s);
			 //debug() << owo(bestPair);
			 a.erase(find(a.begin(), a.end(), bestPair.f));
			 a.erase(find(a.begin(), a.end(), bestPair.s));
			 
			 if(a.empty()) {
				 break;
			 }
			 
			 auto itr = min_element(b.begin(), b .end());
			 assert(itr != b.end());
			 total += *itr;
			 ans.push_back({*itr, -1});
			 a.push_back(*itr);
			 b.erase(itr);
			 
			 sort(a.begin(),a.end());
		}
		
		
		printf("%d\n", total);
		for(auto p : ans) {
			printf("%d", p.f);
			if(p.s != -1) printf(" %d", p.s);
			puts("");
		}
		if(qq) puts("");
	}
		
	return 0;
}
