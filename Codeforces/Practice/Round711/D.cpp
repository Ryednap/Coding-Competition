#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second
const int OO = (int)1e5;

// Finish complexity analysis and then visit here


int main() {
    int n, m;
    scanf("%d %d",&n, &m);

	vector<long long> dp(m + 1, OO);

	dp[0] = 0;
    for(int time = 1; time <= n; ++time) {
        long long t, x, y;
        scanf("%lld %lld %lld", &t, &x, &y);


        auto Get = [&] (long long k) {
            if(t == 1) {
                return ceil(k + x / 1e5);
            } else {
                return ceil(k * x / 1e5);
            }
        };
		
		vector<long long> newDp = dp;
        for(int k = 0; k <= m; ++k) {
            if(dp[k] == OO) continue;

            long long here = k;
            for(int a = 1; a <= y; ++a) {
                here = Get(here);
                if(here > m || dp[here] != OO) break;
                newDp[here] = time;
            }
        }
        dp = newDp;
    }

    for(int i = 1; i <= m; ++i) {
        printf("%lld ", dp[i] == OO ? -1 : dp[i]);
    }
    puts("");
}
