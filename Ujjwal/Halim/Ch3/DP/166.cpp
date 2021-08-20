#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int NAX = 500 + 10;

bool scan (int arr [] ) {
	bool ok = true;
	for(int i = 0; i < 6; ++i) {
		scanf("%d", &arr[i]);
		if(arr[i]) ok = false;
	}
	
	return !ok;
}


const int OO = (int)1e9;

int main() {
	int arr[] = {5, 10, 20, 50, 100, 200};
	int count[6];
	
	while (scan(count)) {
		double amount; scanf("%lf", &amount);
		int n = round(amount * 100.00); // precision lost error actually I faced in this 2 problems and that has counted lik 10 WA on my account due
										// to multiple tap on submit 5 solutions at a go got submitted. damn.
		vector<int> coins;
		for(int i = 0; i < 6; ++i) {
			for(int j = 0; j < count[i]; ++j) {
				coins.push_back(arr[i]);
			}
		}
		
		// dp1  customer's possiblilty with restriction
		// dp2  shopkeer's possiblity no restriction unlimited coin.
		int dp1[NAX], dp2[NAX];
		for(int i = 0; i < NAX; ++i) {
			dp2[i] = dp1[i] = OO;
			
		}
		dp1[0] = dp2[0] = 0;
		
		for(int x : coins) {
			for(int j = NAX - x - 1; j >= 0; --j) {
				dp1[j + x] = min(dp1[j + x], dp1[j] + 1);
			}
		}
		
		for(int i = 0; i < NAX; ++i) {
			for(int j = 0; j < 6; ++j) {
				if(i + arr[j] < NAX) dp2[i + arr[j]] = min(dp2[i + arr[j]], dp2[i] + 1);
			}
		}
		
		
		
		for(int i = 0; i < NAX; ++i) {
			for(int j = i + 1; j < NAX; ++j) {
				dp1[i] = min(dp1[i], dp1[j] + dp2[j - i]);
			}
		}
		//debug() << owo(n) owo(amount);
		printf("%3d\n", dp1[n]);
	}
	
	return 0;
}
