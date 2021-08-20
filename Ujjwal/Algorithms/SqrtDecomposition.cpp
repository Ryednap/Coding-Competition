#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int> ;
#define f first
#define s second

const int nax = (int)1e6 + 10;

int main() {
    int qq;
    scanf("%d", &qq);
    while (qq-- ) {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        int len = sqrt(n + .0) + 1;
        map<pii, long long> rmq;

        auto Preprocess = [&] ( ) {
            for(int i = 0; i < n; i += len) {
                long long sum = 0;
                for(int j = i; j < min (i + len, n); ++j) {
                    sum += arr[j];
                }
                rmq[make_pair(i, min(i + len - 1, n - 1))] = sum;
            }
        };

        auto Query = [&] (int l, int r) {
            long long ans = 0;
            for(auto p : rmq) {
                pii range = p.f;
                auto sum = p.s;
                if(range.f > r) break;
                else if(range.s < l) continue;
                else if(range.f >= l && range.s <= r) ans += sum;
                else {
                    for(int i = max(l, range.f); i <= min(r, range.s); ++i) { // Actually this loop can never more than O(sqrt(n)) times as it can
																			 // never contain more than 2 blocks to run more than 2 times.				
                        ans += arr[i];
                    }
                }
            }
            return ans;
        };
		Preprocess();
        int q;
        scanf("%d", &q);
        while (q-- ) {
            int l, r;
            scanf("%d %d", &l, &r);
            --l, --r;
            printf("%lld\n", Query(l, r));
        }
    }
    return 0;
}


