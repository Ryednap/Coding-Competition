#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int OO = (int)1e9 + 10;
int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d",&n);
		int a[n];
		for(int i = 0 ; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int answer = -OO;
		int mini = a[n - 1];
		for(int i = n - 2; i >= 0; --i) {
			answer = max(answer, a[i] - mini);
			mini = min(mini, a[i]);
		}
		//int maxi = a[0];
		//for(int i = 1; i < n; ++i) {
			//answer = max(answer, maxi - a[i]);
			//maxi = max(maxi, a[i]);
		//}
		printf("%d\n", answer);
	} 
	return 0;
}
