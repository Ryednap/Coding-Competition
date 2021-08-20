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
	scanf("%d", &qq);
	while (qq--) { 
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		bool ok = true;
		for(int i = 1; i < n; ++i) {
			if(a[0] != a[i] && a[0] > (a[i] - 1) >> 1)
				ok = false;
		}
		if(!ok) printf("%d\n", n);
		else {
			int ans = 1;
			for(int i = 1; i < n; ++i)
				if(a[0] == a[i])
					++ans;
			printf("%d\n", n - ans);
		}
	}
	return 0;
}