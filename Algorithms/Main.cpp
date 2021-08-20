#include <bits/stdc++.h>

using ll = long long;
using vi = std::vector<ll>;

int main() {
    int qq;
    scanf ("%d", &qq);
    while (qq--) {
        int n;
        scanf ("%d", &n);
        vi a(n);
        for (ll & x : a) {
            scanf ("%lld", &x);
        }
        if(n == 1) {
            puts("1");
            continue;
        }
        vi sec;
        for (int i = 1; i < n; ++i) {
            sec.push_back(abs(a[i] - a[i - 1]));
        }
        n = (int)sec.size();
        int ans = 0;
        ll GCD = sec[0];
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && std::__gcd(GCD, sec[j]) > 1) {
            	GCD = std::__gcd(GCD, sec[j]);
                ++j;
            }
            ans = std::max(ans, j - i + 1);
        }
        printf ("%d\n", ans);
    }
}