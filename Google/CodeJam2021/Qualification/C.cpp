#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Nice constructive O(N) solution
// The constructivness is based on the IDEA that for any sequence a1, a2, a3 ... an the max cost is
// (n + n - 1 + n - 2 ..) to get this the order should be  a2 a3 a5 .... .. a6 a4 a1
// So our target should be ulitimately arrive at this order


// Now the orginal sequence has cost of n, to get n + 1 reverse [1 .. 2], to get n + 2 reverse
// [1 .. 3] ... and so on to get the cost n + n - 1 reverse [1 .. n], now to get more than that i.e
// n + n - 1 + 1, we need to repeat this process but note that here at most we can go upto n - 2.
// continue this until you find the desired result.

int Cost(vector<int> arr) {
	int ans = 0;
	for(auto itr = arr.begin(); itr != arr.end() - 1; ++itr) {
		auto j = min_element(itr, arr.end());
		ans += (int)(j - itr + 1);
		reverse(itr, j + 1);
		//debug() << owo(arr);
	}
	return ans;
}

void Solve() {
	int N, C;
	scanf("%d %d", &N, &C);
	int maxCost = ((N * (N + 1)) >> 1) - 1;
	int minCost = N - 1;
	
	vector<int> ans(N);
	for(int i = 1; i <= N; ++i) {
		ans[i - 1] = i;
	}
	
	if(C <= maxCost && C >= minCost) {
		int start = 0, end = N - 1, turn = 0;
		int n = N - 2, copy = C;
		while (true && end > start) {

			int costHere = (end - start + 1) + n;
			//debug() << owo(ans) owo(costHere) owo(C);
			if(C <= costHere) {
				int pos = C - n;
				//debug() << owo(start) owo(end) owo(pos) owo(ans);
				reverse(ans.begin() + start, ans.begin() + start + pos);
				break;

			} else {
				reverse(ans.begin() + start, ans.begin() + end + 1);
				C -= (end- start + 1);
				if(turn) ++start;
				else --end;
				--n;
				turn ^= 1;
				
			}
		}

		assert(Cost(ans) == copy);
		printf("%d", ans[0]);
		for(int i = 1; i < N; ++i) {
			printf(" %d", ans[i]);
		}
		puts("");
		
	} else puts("IMPOSSIBLE");

}


int main() {
	int qq;
	scanf("%d", &qq);
	for(int i = 1; i <= qq; ++i) {
		printf("Case #%d: ", i);
		Solve();
	}
	
	return 0;
}
