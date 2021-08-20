#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int brr[n];
    int r = sum % n;
    for(int i = 0; i < r; ++i) {
        brr[i] = (sum + n - 1) / n;
    }
    for(int i = r; i < n; ++i) {
        brr[i] = sum / n;
    }

    sort(arr, arr + n);
    sort(brr, brr + n);

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += abs(arr[i] - brr[i]);
    }

    printf("%d\n", ans >> 1);
    return 0;
}