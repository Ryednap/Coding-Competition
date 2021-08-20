#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;

#define f first
#define s second

int dp[1000][1000];

int nCk (int n, int k) {
    if(k > n) return 0;
    if(k == 0) return 1;
    if(k == n) return 1;
    int & res = dp[n][k];
    if(res != -1) return res;
    return res = nCk(n - 1, k - 1) + nCk(n - 1, k);
}

int Sum(vector<pii> v) {
    int sum = 0;
    for(auto p : v) {
        sum += nCk(p.f - 1, p.s - 1);
    }
    return sum;
}

void Solve() {
    int N;
    scanf("%d", &N);

    vector<pii> left, right;
    for(int i = 1; i <= 30; ++i) {
        left.emplace_back(i, 1);
        right.emplace_back(i, i);
    }
    int temp = N;
    N -= 30;
    if(N > 0) {
        vector<pii> ans;
        int turn = 1;

        for(int i = 0; i < 30; ++i) {
            if(N & (1LL << i)) {
                turn ^= 1;

                for(int j = 1; j <= i + 1; ++j) {
                    ans.emplace_back(i + 1, j);
                }

            } else {
                if(turn) ans.push_back(left[i]);
                else ans.push_back(right[i]);
            }
        }
        debug() << owo(Sum(ans));
        debug() << owo(ans);
        assert(Sum(ans) == temp);
        for(auto p : ans) {
            printf("%d %d\n", p.f, p.s);
        }

    } else {
        int sum = 0;
        for(int i = 0; i < temp; ++i) {
            printf("%d %d\n", left[i].f, left[i].s);
            
        }
    }

}

int main() {
    memset(dp, -1, sizeof(dp));
    int qq;
    scanf("%d", &qq);
    for(int tt = 0; tt < qq; ++tt) {
        printf("Case #%d:\n", tt + 1);
        Solve();
    }
    return 0;
}