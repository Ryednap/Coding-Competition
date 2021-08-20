#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif
using ll = long long;
using vi = std::vector<int>;


int main() {
    std::vector<std::string> store;
    std::string def = "abc";
    do {
        store.push_back (def);
    } while (next_permutation(def.begin(), def.end()));

    int qq = 1;
    while (qq--) {
        int n, m;
        scanf ("%d %d", &n, &m);
        std::string s;
        std::cin >> s;

        std::vector< std::vector <int>> dp (6, std::vector<int> (n + 1, 0));
        for (int i = 0; i < 6; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1] + (s[j - 1] != store[i][(j - 1 + j) % 3]);
            }
        }

        while (m--) {
            int l, r; 
            scanf ("%d %d", &l, &r);
            --l, --r;
            int ans = (int)1e9;
            for (int i = 0; i < 6; ++i) {
                ans = std :: min (ans, dp[i][r + 1] - dp[i][l]);
            }
            printf ("%d\n", ans);
        }
    }
    return 0;
}
