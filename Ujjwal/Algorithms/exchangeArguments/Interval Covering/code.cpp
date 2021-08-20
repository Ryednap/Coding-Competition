#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

int main() {
    int n;
    scanf("%d", &n);
    pii arr[n]; // pair of events

    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &arr[i].f, &arr[i].s);
    }

    // sorting by the increasing first and decresing second in case of tie.
    sort(arr, arr + n, [](const pii &a, const pii & b){
        if(a.f == b.f) return a.s > b.s;
        return a.f < b.f;
    });

    int req, curr = 0;
    scanf("%d", &req);
    pii prev = {-1, -1};
    set<pii> ans;


    // Main greedy starts here
    bool valid = true;
    for(int i = 0; i < n; ++i) {

        if(curr >= req) break; // target reached

        if(arr[i].f <= curr && arr[i].s > curr) { // arr[i] possible candidate for next picking
            if(prev.s < arr[i].s) prev = arr[i];

        } else if( arr[i].f > curr ) { // we reached one threshold now time for inserting the best previous candidate.
            if(prev.f > curr || prev.s <= curr) {
                valid = false; // not enough cover
                break;
            }

            ans.insert(prev);
            curr = prev.s;
            prev = arr[i];
        }
    }

    if(curr < req && prev.f <= curr && prev.s > curr) { // Just extra precaution
        ans.insert(prev);
        curr = prev.s;
    }

    valid &= (curr >= req);

    if(valid) {
        printf("%d\n", (int)ans.size());
    } else puts("-1");

    return 0;
}