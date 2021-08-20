#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = 60;
const int INF = 100;
int n, c;
string s;
int dp[nax][nax][nax];

int Brute(int i, int j, int k) {
    if(k > c) return INF;
    if(i == n) return 0;
    int & ans = dp[i][j][k];
    if(ans != -1) return ans;
    if(s[i] == '.') return ans = Brute(i + 1, j, k + 1);
    if(s[i] == '*') return ans = min(Brute(i + 1, i, 0) + 1, Brute(i + 1, j, k + 1));
    assert(false);
    return 0;
}

int main() {
    int qq;
    scanf("%d", &qq); 
    while (qq--) {
        scanf("%d %d", &n, &c);
        cin >> s;
        memset(dp, -1, sizeof(dp));

        int first = n, last = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '*') first = min(first, i), last = max(last, i);
            
        }
        int m = n;
        n = last;
        int answer = Brute(first, 0, 0);
        if(first == m) printf("%d\n", 0);
        else if(first == last) printf("%d\n", answer + 1);
        else printf("%d\n", answer + 2);
    }
    return 0;
}