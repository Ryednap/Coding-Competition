#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using pii = pair<int, int>;
using vpi = vector<pii>;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		vpi arr(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &arr[i].f, &arr[i].s);
		}
		sort(arr.begin(), arr.end(), [](const pii & a, const pii & b){
			if(a.f == b.f) return a.s > b.s;
			else return a.f > b.f;
		});

		debug() << owo(arr);

		auto Comp = [&] (pii & a, pii & b) {
			return (a.f < b.f && a.s < b.s);
		};

		vector<int> dp(n);
		int answer = 0;
		for(int i = 0; i < n; ++i) {
			dp[i] = 1;
			for(int j = 0; j < i; ++j) {
				if(arr[j].f >= arr[i].f && arr[j].s >= arr[i].s) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			answer = max(answer, dp[i]);
			debug() << owo(dp);
		}
		printf("%d\n", answer);
/* 

		vector<int> dp(n);
		int answer = 0;
		for(int i = 0; i < n; ++i) {
			dp[i] = 1;
			for(int j = 0; j < i; ++j) {
				if(arr[j].s > arr[i].s)
					dp[i] = max(dp[i], dp[j] + 1);
			}
			answer = max(answer, dp[i]);
		}

		printf("%d\n", answer); */
	}
			
	return 0;
}
