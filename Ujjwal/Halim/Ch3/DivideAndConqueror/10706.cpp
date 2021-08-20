#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int nax = 65535 + 10;

// Binary search can be done
// But a bit of state-space analysis can avoid that very nice problem. Recommended.

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		long long n, total = 0, prev = 0;
		scanf("%lld", &n);
		
		for(int i = 1; i < nax; ++i) {
			prev = prev + log10(i) + 1;
			
			if(total + prev >= n) {
				n -= total;
				total = 0;
				
				for(int j = 1; j <= i; ++j) {
					if(total + log10(j) + 1 >= n) {
						n -= total;
						total = 0;
						
						string s = to_string(j);
						printf("%c\n", s[n - 1]);
						
						break;
								
					} else total += log10(j) + 1;
				}
				
				break;
			} else total += prev;
		}
	}
	
	
	return 0;
}
