#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
Note that You can convert the problem to finding LIS by the same idea explained for THE PCB problem on USACO website.
As the sequence is guranteed to be a permutation for each element we can store where it occurs and then we can use the fact
all the elements that constitute common subsequence must form an increasing order by index of their occurence in both the 
sequence. i.e if [a, b] forms a sequence and suppose positions are [x, x'] and [y, y'] in both the permutation respectively
then (x < y and x' < y') so fix one permutation to clear of the x parameter then find lis on x' and y'.

*/

const int OO = (int)1e9;

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> mapper;
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d",&x);
        mapper[x] = i;
    }

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        arr[i] = mapper[x];
    }

    int answer = 0;
    vector<int> dp(n + 1, OO);
    dp[0] = -OO;
    for(int i = 0; i < n; ++i) {
        int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if(j <= n && arr[i] > dp[j - 1]) {
            answer = max(answer, j);
            dp[j] = arr[i];
        }
    }
    printf("%d\n", answer);
    return 0;
}