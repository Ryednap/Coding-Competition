#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
#include "uj.h"
#endif

class BallotCounting {
    public:
        int count(string votes) {
            const int n = (int)votes.length();
            int A = 0, B = 0;
            int ans = 0, half = n >> 1;
            for(char ch : votes) {
                if(ch == 'A') ++A;
                else ++B;
                ++ans;

                if(A > half || B > half) break;
            }
            return ans;
        }
};
