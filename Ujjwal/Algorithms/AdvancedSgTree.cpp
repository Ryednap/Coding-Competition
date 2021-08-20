#include <bits/stdc++.h>

/** 
    Given an array find the maximum/minimum and the maximum number of times it occurs

**/

using namespace std;
#ifdef LOCAL 
#include "uj.h"
#endif

using pii = pair<int, int> ;
#define f first
#define s second


class SegmentTree {
    public :
        SegmentTree (vector<int> & v) {
            A = v;
            const int n = (int)v.size();
            st.assign(3 * n + 1, make_pair(0, 0));
            lo.resize(4 * n + 1), hi.resize(4 * n + 1);
            Init (1, 0, n - 1);
        }

        void Update (int pos, int value) {
            Update (1, pos, value);
        }

        pii Query (int l, int r) {
			debug() << owo(st);
            return Query (1, l, r);
        }

    private :
        vector<pii> st;
        vector<int> lo, hi, A;
        
    private :

        pii Combine (pii & a, pii & b) {
            if(a.f > b.f) return a;
            else if(b.f > a.f) return b;
            else return  {a.f, a.s + b.s};
        }
            
        void Init (int i, int l, int r) {
            lo[i] = l;
            hi[i] = r;
            if(l == r) {
               st[i] = make_pair( A[l], 1);
               return; 
            }

            int mid = (l + r) >> 1;
            Init (i << 1, l, mid);
            Init ((i << 1) + 1, mid + 1, r);

            st[i] = Combine(st[i << 1], st[(i << 1) + 1]);
        }

        void Update (int i, int pos, int value) {
            debug() << owo(lo[i]) owo(hi[i]) owo(i) owo(pos) owo(value);
            if(lo[i] > pos || hi[i] < pos) return;
            else if(hi[i] == lo[i] ) {
				puts("hi");
                st[i] = make_pair(value, 1);
                return;
            }
            Update(2 * i, pos, value);
            Update(2 * i + 1, pos, value);

            st[i] = Combine(st[2 * i], st[2 * i + 1]);
        }

        pii Query (int i, int l , int r) {
            if(lo[i] >= l && hi[i] <= r) {
                return st[i];
                
            } else if(lo[i] > r || hi[i] < l) return {-INT_MAX, 0};

            pii a = Query ( i << 1, l, r);
            pii b = Query ( (i << 1) + 1, l, r);

            return Combine(a, b );
        }
};


int main() {
	std :: vector<int> v = {1, 2, 3, 4, 5};
	SegmentTree sg(v);
	debug() << owo( sg.Query(1, 3) );
	sg.Update(2, 4)
    return 0;
}
