#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
const int nax = (int)1e6 + 10;


int main() {
	vi div(nax, 0);
	
	for(int i = 1; i < nax; ++i) {
		for(int j = 1; j * i < nax; ++j) {
			div[i * j]++;
		}
	}
	
	vi seq;
	int prev = 1;
	seq.push_back(1);
	while (prev < nax) {
		prev = prev + div[prev];
		seq.push_back(prev);
	}
	
	
	int qq, tt = 0;
	scanf("%d",&qq);
	while (qq--) {
		int A, B;
		scanf("%d%d", &A, &B);
		auto a = lower_bound(seq.begin(), seq.end(), A);
		auto b = lower_bound(seq.begin(), seq.end(), B);
		if(*a < A) a++;
		if(*b > B) --b;
		
		printf("Case %d: %d\n", ++tt, (int)(b - a + 1));
	}
		
			
	return 0;
}
