#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main( ) {
	int qq;
	scanf("%d", &qq) ;
	while( qq -- ){
		int n, k;
		scanf("%d %d", &n, &k);
		int x = n - k;
		for(int i = 1; i <= k; ++i) {
			if( i < k - x) printf("%d ", i);
			else printf("%d " , k + k - x - i);
		}
		puts("");
	}
	
	return 0;	
}
