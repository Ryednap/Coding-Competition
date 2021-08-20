#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = 20;

int main() {
    int qq;
    scanf("%d", &qq);
    while (qq--) {
        string a, b;
        cin >> a >> b;

        const int n = (int)a.length();
        const int m = (int)b.length();

        int answer = 100;
        for(int i = 0; i < n; ++i) {
            for(int j = n; j >= i; --j) {
                for(int k = 0; k < m; ++k) {
                    for(int l = m; l >= k; --l) {

                        string s = a.substr(i, j - i);
                        string t = b.substr(k, l - k);
                        if(s == t) {
                            int cost1 = (int)a.length() - (int)s.length();
                            int cost2 = (int)b.length() - (int)t.length();
                            answer = min(answer, cost1 + cost2);
                        }
                    }
                }
            }
        }

        printf("%d\n", answer);
        
    }
    return 0;
}