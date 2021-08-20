#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif



int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	for(int i = 0; i < n; ++i) {
		long long x;
		scanf("%lld", &x);
		Add(x);
	}
	
	
	return 0;
}
