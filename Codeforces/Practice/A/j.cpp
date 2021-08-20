#include <bits/stdc++.h>
using namespace std;

/*
 * Points to be noted
 * c0 + c1 + c2 = n
 * as n % 3 == 0 so c0 = c1 = c2 = n / 3
 * now the cycle is c0 -> c1 -> c2 -> c0 and so on
 * Also <= 2 of (c0, c1, c2) are > n / 3, so just go the larger one and do the process until it balances.
 */

int main() {
	int qq;
	scanf("%d",&qq);
	while (qq--) {
		int n;
		scanf("%d",&n);
		array<int, 3> ar = {0};
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d",&x);
			ar[x%3]++;
		}
		int a = n / 3;
		int ans = 0;
		for(int i = 0; i < 3; ++i) {
			if(ar[i] > a) {
				while( ar[i] > a) {
					int give = ar[i] - a;
					ans += give;
					ar[i] = a;
					i = (i + 1)%3;
					ar[i] += give;
				}
			}
		}
		printf("%d\n",ans);
	}
}

/*
 * Tricky Case
 * when c0, c1, c2 = [4 1 4] here the process continues;
 * 
 */
