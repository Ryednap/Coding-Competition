#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		
		int A, B, n;
		scanf("%d%d%d", &A, &B, &n);
		int a[n], b[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for(int i= 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			int p = (b[i] + A - 1) / A;
			B -= p * a[i];
		
		}
		
		puts(ok ? "Yes" : "No");
	}
		
	return 0;	
}
