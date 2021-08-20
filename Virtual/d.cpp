#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
    int qq;
    scanf("%d", &qq);
    while (qq--) {
        int n;
        scanf("%d", &n);
        map<int, int> mapper;
        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            mapper[x]++;
        }

        priority_queue<int> pq;
        for(auto p : mapper) {
            pq.push(p.second);
        }
        int answer = 0;
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            while (x && !pq.empty()) {
                int y = pq.top(); pq.pop();
                if(y) {
                    pq.push(y - 1);
                    --x;
                }
            }
            
            if(x) {
                answer = x;
                assert(pq.empty());
                break;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}