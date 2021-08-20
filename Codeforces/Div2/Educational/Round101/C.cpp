#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// A bit tougher for me I would say this was a greedy solution.

/* During upsolving i had a similar idea but what i was making mistake was this that i was considering hi and lo as maximum and minimum height that we
 * can have for the current block now when we reach the end of the block then we can check if this range is in intersection. Also discard any intermediate
 * block if it doesnot satisfies the range
 */
 
 /* Well that was corect but i guess the better idea would be to fix the range for the base rather than the whole thing
  */

bool Intersect(auto a, auto b){
	if(a[0] <= b[0] && a[0] >= b[1]) return true;
	if(a[1] <= b[0] && a[1] >= b[1]) return true;
	
	return false;
}
const long long nax = (int)1e16 + 10;
int main(){
	int tt;
	scanf("%d", &tt);
	while(tt -- ) {
		int n, k;
		scanf("%d %d", &n, &k);
		long long H[n];
		for(int i = 0; i < n; ++i){
			scanf("%lld", &H[i]);
		}
		
		//                hi     lo
		long long r[2] = {H[0] , H[0]};
		auto Set = [&](int j){
			r[0] = min(r[0] + k - 1, H[j] + k - 1);
			r[1] = max(r[0] - k + 1, H[j]);
			if(r[0] < r[1]) return false;
			return true;
		};
		
		
		bool ok = true;
		for(int i = 1; i < n - 1; ++i){
			ok &= Set(i);
		}
		long long l[2] = {H[n - 1] , H[n - 1]};
		ok &= (Intersect(l, r) || Intersect(r, l));
		puts(ok ? "Yes" : "No");
	}
	return 0;
}
