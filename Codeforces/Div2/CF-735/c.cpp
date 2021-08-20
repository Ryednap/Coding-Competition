#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;

#define f first
#define s second

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, m;
		scanf("%d %d",&n, &m);
		ll ans = 0;
		int len1 =  m != 0 ? log2(m) + 1 : 1;
		int len2 =  n != 0 ? log2(n) + 1 : 1;
		const int x = max(len1, len2);
		for (int i = x; i >= 0; --i) {
			bool zeroPresent = false;
			int bit = m & (1 << i);
			int here = n & (1 << i);
			if(!bit) {
				if(here) break;
				for(int j = i - 1; j >= 0; --j) {
					if(!(m & (1 << j))) {
						zeroPresent = true;
						break;
					}
				}
				if(!zeroPresent && !here) {
					ans |= (1 << i);
					break;
				}

			} else if(!here) {
				ans |= (1 << i);
			}	
		}
		printf("%lld\n", ans);
	}
	return 0;
}