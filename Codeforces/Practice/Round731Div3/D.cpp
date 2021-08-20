#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		int b[n], c[n];
		b[0] = 0;
		scanf("%d", &c[0]);
		for(int i = 1; i < n; ++i) {
			int x; scanf("%d", &x);
			b[i] = 0;
			c[i] = c[i - 1];
			//debug() << owo(b[i]) owo(c[i]) owo(x);
			for(int j = 0; j < 31; ++j) {
				int bita = x & (1 << j);
				int bitc = c[i] & (1 << j);
				//debug() << owo(bita) owo(bitb) owo(bitc);
				if(bitc != 0 && bita == 0) {
					b[i] |= (1 << j);
				}
			}
			c[i] = x ^ b[i];
		}

		for(int i = 0; i < n; ++i) {
			printf("%d ", b[i]);
		}
		puts("");
	}
}