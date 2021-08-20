#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
vector<pii> ans;
set<pii> used;
int N;

int dx [] = {-1, -1, 0, 0, 1, 1};
int dy [] = {-1, 0, -1, 1, 0, 1};

int dp[1000][1000];

int nCk (int n, int k) {
    if(k > n) return 0;
    if(k == 0) return 1;
    if(k == n) return 1;
    int & res = dp[n][k];
    if(res != -1) return res;
    return res = nCk(n - 1, k - 1) + nCk(n - 1, k);
}

bool Valid (int x, int y) {
    if(x < 0 || y < 0 || y > x) return false;
    if(used.find(make_pair(x, y)) != used.end()) return false;
    return true;
}
/* 
int maxi_n = 0, maxi_m = 0; */

bool found = false;
void Brute(int i, int j, int sum) {
  /*   maxi_n = max(maxi_n, i);
    maxi_m = max(maxi_m, j);
    debug() << owo(maxi_n) owo(maxi_m); */
    if((int)used.size() > 500) return;
    if(sum == N) {
        found = true;
        int check = 0;

        for(auto p : used) {
            printf("%d %d\n", p.first  + 1 ,p.second + 1);
            check += nCk(p.first, p.second);
          /*   debug() << owo(p) owo(nCk(p.first, p.second)); */
        }
        assert(check == sum);

    } else if(sum > N) return;

    if(found) return;

    for(int k = 0; k < 6; ++k) {
        int RR = i + dx[k];
        int CC = j + dy[k];
        if(found) return;
        if(Valid(RR,CC)) {
            ans.emplace_back(RR, CC);
            used.insert(make_pair(RR, CC));
            Brute(RR, CC, sum + nCk(RR, CC));
            if(found) return;
            used.erase(make_pair(RR, CC));
            ans.pop_back();
        }
    }
}

void Solve() {
    scanf("%d", &N);
    found = false;
    used.clear();
    ans.clear();
    used.insert(make_pair(0, 0));
    ans.emplace_back(0, 0);
    Brute(0, 0, 1);
    assert(found);
}

int main() {
    int qq;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &qq);
    for(int tt = 0; tt < qq; ++tt) {
        printf("Case #%d:\n", tt + 1);
        Solve();
    }
    return 0;
}