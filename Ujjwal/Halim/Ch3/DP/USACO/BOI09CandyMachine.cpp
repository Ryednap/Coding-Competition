#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<long long, long  long> ;
#define f first
#define s second

int main() {
	int n;
	scanf("%d", &n);
	vector<pii> arr;
	for(int i = 0; i < n; ++i) {
		int s, t;
		scanf("%d %d", &s, &t);
		arr.emplace_back(t, s);
	}

	vector<pair<int, pii>> answer;
	int count = 1;

	auto Valid = [&] (int i, int j) {
		return arr[i].f - arr[j].f >= abs(arr[i].s - arr[j].s);
		return false;
	};

	while (!arr.empty()) {
		sort(arr.begin(), arr.end());
		n = (int)arr.size();
		vector<pii> dp(n);
		for(int i = 0; i < n; ++i) {
			dp[i] = make_pair(1, i);
			for(int j = 0; j < i; ++j) {
				if(Valid(i, j) && dp[i].f < dp[j].f + 1) {
					dp[i].f = dp[j].f + 1;
					dp[i].s = j;
				} else if(Valid(i, j) && dp[i].f == dp[j].f + 1) {
					int x = abs(arr[i].s - arr[j].s);
					int y = abs(dp[i].s - arr[i].s);
					if(x < y) dp[i].s = j;	
				}
			}
		}

		int where = 0;
		for(int i = 0; i < n; ++i) {
			if(dp[where].f < dp[i].f) where = i;
		}

		map<int, int> invalid;
		while (dp[where].s != where) {
			invalid[where] = true;
			where = dp[where].s;
		}
		invalid[where] = true;
		vector<pii> newArr;
		for(int i = 0; i < n; ++i) {
			if(!invalid[i]) newArr.push_back(arr[i]);
			else {
				answer.emplace_back(count, arr[i]);
			}
		}
		++count;
		arr = newArr;
	}

	printf("%d\n", count - 1);
	for(int i = 0; i < (int)answer.size(); ++i) {
		printf("%lld %lld %d\n", answer[i].s.s, answer[i].s.f, answer[i].f);
	}
    return 0;
}
