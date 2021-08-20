#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	long long n, l, u;
	while (scanf("%lld %lld %lld", &n, &l, &u) != EOF) {
		long long ans = 0;
		for(int i = 32; i >= 0; --i) {
			if(n & (1LL << i)) {
				
				long long temp = ans | ((1LL << i) - 1);
				if(temp < l) ans |= (1LL << i); 
				
			} else {
				long long temp = ans | (1LL << i);
				if(temp <= u) ans |= (1LL << i);
			}
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
