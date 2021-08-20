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
	while(qq -- ) {
		int n, m;
		scanf("%d %d",&n, &m);
		int k[n], a[m];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &k[i]);
			--k[i];
		}
		sort(k , k + n, greater<int>());
		for(int i = 0;i < m; ++i) {
			scanf("%d",&a[i]);
		}
		long long answer = 0;
		for(int i = 0, j = 0; i < n; ++i) {
			if(j < m && a[j] < a[k[i]]) answer += a[j++]; 
			else answer += a[k[i]];
		}
		printf("%lld\n", answer);
	}
	return 0;
}
