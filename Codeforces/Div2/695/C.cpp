#include <bits/stdc++.h>
using namespace std;

int main() {
	array<int, 3> n;
	for(int i = 0; i < 3; ++i) {
		scanf("%d", &n[i]);
	}
	
	array<vector<int>, 3> ar;
	for(int i = 0; i < 3; ++i) {
		ar[i].resize(n[i]);
		for(int & x : ar[i]) {
			scanf("%d", &x);
		}
		sort(ar[i].begin(), ar[i].end());
	}
	
	auto Sum = [] (auto x) {
		return accumulate(x.begin(), x.end(), 0LL);
	};
	
	int64_t answer = 0;
	// consider a bag to be all negative
	for(int i = 0; i < 3; ++i) {
		int64_t maybe = -Sum(ar[i]);
		for(int j = 0 ; j < 3; ++j) {
			if(i != j) maybe += Sum(ar[j]);
		}
		answer = max(answer, maybe);
	}
	
	// condier two distinct bag  elements to be negative.
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(i == j) continue;
			for(int k = 0; k < 3; ++k)  {
				if(k == i || k == j) continue;
				int64_t maybe = Sum(ar[i]) - 2 * ar[i][0] +  Sum(ar[j]) - 2 * ar[j][0] + Sum(ar[k]);
				answer = max(answer, maybe);
			}
		}
	}
	
	printf("%lld\n", answer);
	return 0;
}
	
		
