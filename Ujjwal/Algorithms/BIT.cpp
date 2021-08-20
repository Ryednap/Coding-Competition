#include <bits/stdc++.h>
using namespace std;

class BIT {
    public : 
        BIT ( int n ) {
           ft.assign(n + 1, 0);
           N = n + 1;
        }

        void Update (int pos, int delta) {
            while( pos < N ) {
                ft[pos] += delta;
                pos += lowestOneBit(pos);
            }
        }

        int rmq (int l, int r) {
            return Sum (r) - Sum(r);
        }


    private :
     vector<int> ft;
     int N;

    private :
        int lowestOneBit (int n ) {
            return (n & -n);
        }

        int Sum (int i) {
            int sum = 0;
            while( i > 0) {
                sum += ft[i];
                i -= lowestOneBit(i);
            }
            return sum;
        }
};

int main () {
    return 0;
}
