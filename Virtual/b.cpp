#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using namespace std;

int main() {
    return 0;
    puts("hello world");
}


int main() {
    int qq;
    scanf("%d", &qq); 
    while (qq--) {
        int n, k;
        scanf("%d %d", &n, &k);
        string s;
        cin >> s;
        int answer = 0;

        int first = n, last = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '*') {
                first = min(first, i);
                last = max(last, i);
            }
        }

        int prev = first, dist = 0;
        for(int i = first + 1; i <= last; ++i) {
            ++dist;
            if(dist > k) {
                ++answer;
                dist = i - prev;
            }

            if(s[i] == '*') {
                prev = i;
            }
        }

        if(first == last) printf("%d\n", answer + 1);
        else if(first == n) printf("%d\n", 0);
        else printf("%d\n", answer + 2);
    }
    return 0;
}