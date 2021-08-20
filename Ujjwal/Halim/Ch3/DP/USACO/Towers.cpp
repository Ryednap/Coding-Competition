#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int OO = (int)1e9;

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    vector<int> dp(n+ 1, OO);

    dp[0] = -OO;
    int answer = 0;
    for(int i = 0; i < n; ++i) {
        int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if(j <= n) {
            dp[j] = arr[i];
            answer = max(answer, j);
        }
    }

    printf("%d\n", answer);

    return 0;
}