#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
    int qq;
    scanf("%d", &qq);
    while( qq --) {
        int n;
        scanf("%d", &n);
        vector<int> a, b;
        set<int> s, t;
        for(int i = 1; i<= n; ++i) {
            s.insert(i);
            t.insert(i);
        }

        int currMax = 0;
        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
   /*          debug() << owo(s) owo(t) owo(x); */
            if(currMax == x) {
                auto itr = t.lower_bound(x); --itr;
                a.push_back(*s.begin());
                s.erase(s.begin());

                b.push_back(*itr);
                t.erase(*itr);

            } else {
                currMax = x;
                a.push_back(x);
                b.push_back(x);
                s.erase(x);
                t.erase(x);
            }
        }

        for(int & x : a) {
            printf("%d ", x);
        }
        puts("");
        for(int & x : b) {
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}