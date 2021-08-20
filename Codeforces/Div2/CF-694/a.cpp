#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif
//debug & operator << (debug & , const ob & o) {
	//d << "( " << o. << " " << o. " )";
	//return d;
//}


int main() {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n, x;
		scanf("%d %d",&n, &x);

		long long lo = 0, sum = 0;
		for(int i = 0; i < n; ++i) {
			int a; 
			scanf("%d", &a);
			sum += a;
			lo += (a + x - 1)/x;
		}
		printf("%lld %lld\n", (sum + x - 1)/x, lo);
		
	}
	return 0;
}
	
