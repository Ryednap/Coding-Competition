#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
#define f first
#define s second



int main() {
	int qq;
	scanf("%d",&qq);
	while (qq--) { 
		int n;
		scanf("%d", &n);
		int a[n], bitCount[32] = {0};
		int x = 0;

		for(int j = 0; j < n; ++j) {
			scanf("%d", &a[j]);
			for(int i = 0; i < 32; ++i) {
				if(a[j] & (1 << i))
					bitCount[i]++;
			}
		}

		for(int i = 0 ; i < 32; ++i) {
			if(bitCount[i] == n)
				x |= (1 << i);
		}

		int ans = 0;
		for(int i = 0; i < n; ++i) {
			ans |= (a[i] ^ x);
		}
		printf("%d %d\n",x, ans);
	}
	return 0;
}