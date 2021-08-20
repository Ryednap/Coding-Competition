#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n^ 2) passes WTF ? 

const int nax = (int)1e6 + 10;
int main() {
	int n;
	char buff;
	while (scanf("%d%c", &n, &buff) && n) {
		
		vector<int> arr(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		

// Method 2		
		bool ok = false;
		int a[nax], b[nax];
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; ++i) {
			b[arr[i]] = 1;
		}
		for(int i = 0; i < n; ++i) {
			for(int d = 1; d <= arr[i]; ++d) {
				if(a[arr[i] - d] && b[arr[i] + d]) {
					ok = true;
					break;
				}
				if(a[arr[i] + d] && b[arr[i] - d]) {
					ok = true;
					break;
					}
			}
			a[arr[i]] = true;
			b[arr[i]] = false;
		}
		puts(ok ? "no" : "yes");
	}
	return 0;
}
