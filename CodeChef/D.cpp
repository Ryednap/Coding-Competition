#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std :: vector<int>;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vi prefGCD(n + 1, 0);
		vi suffGCD(n + 1, 0);
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			prefGCD[i + 1] = std :: __gcd(prefGCD[i], arr[i]);
		}
		if(n == 1) {
			puts("1");
			continue;
		}

		for(int i = n - 1; i >= 0; --i) {
			suffGCD[i] = std :: __gcd(suffGCD[i + 1], arr[i]);
		}

		int maxi = 0;
		for(int i = 0; i < n; ++i) {
			maxi = std :: max(maxi, __gcd(suffGCD[i + 1], prefGCD[i]));
		}

		assert(maxi != 0);
		long long answer = 0, secondMaxi = 0;
		bool ok = false;
		for(int i = 0; i < n; ++i) {
			if(arr[i] % maxi == 0) {
				secondMaxi = std :: max(secondMaxi, (long long) arr[i] / maxi);
				answer += arr[i] / maxi;
			} else {
				ok = true;
				answer += 1;
			}
		}
		if(!ok) answer = answer - secondMaxi + 1;
		printf("%lld\n", answer);
	}
	return 0;
}