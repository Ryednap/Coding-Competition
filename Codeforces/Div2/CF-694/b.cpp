#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif
//debug & operator << (debug & , const ob & o) {
	//d << "( " << o. << " " << o. " )";
	//return d;
//}

using pii = pair<int ,int>;
#define f first
#define s second

int main() {
	int qq;
	scanf("%d",&qq);
	while(qq -- ) {
		int n, x;
		scanf("%d %d",&n, &x);
		vector<pii> arr(n);
		for(pii & p : arr) {
			scanf("%d", &p.f);
			p.s = 1;
		}
		
		for(int i = 0; i < (int)arr.size() ; ++i) {
			int a = arr[i].f;
			int b = arr[i].s;
				if(a % x != 0) break;
			arr.push_back( {a/x, x *  b});
		
		}

		long long sum = 0;
		//debug() << owo(arr.size());
		for(int i =0; i < (int)arr.size() ; ++i) {
			sum += arr[i].f * arr[i].s;
		}
		printf("%lld\n", sum);

	} 
	return 0;
}
