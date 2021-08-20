#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class SegmentTree {
    public :
        SegmentTree (int n) {
            st.assign(3 * n,0);
            delta.assign(4 * n , 0);
            lo.resize(4 * n), hi.resize(4 * n);
            Init (1, 0, n - 1);
        }
        
        void Update(int l, int r, int c) {
			Update(1, l, r, c);
		}
        
        int Query (int l, int r) {

			return Query(1, l, r);
		}

    private :
       vector<int> st, delta;
       vector<int> lo, hi;

    private :
        void Init (int i, int l, int r) {
            lo[i] = l;
            hi[i] = r;
            if(l == r) {
               return;
            }

            int mid = (l + r)  >> 1;
            Init (2 * i, l, mid);
            Init (2 * i + 1, mid + 1, r);
        }
        
        void Set (int i) {
            st[i] = min(st[2 * i] + delta[2 * i], st[2 * i+ 1] + delta[2 * i + 1]);
        }

        void Prop (int i ) {
            delta[2 * i] += delta[i];
            delta[2 * i + 1] += delta[i];
            delta[i] = 0;
        }

        void Update (int i, int l, int r, int c) {
            if(lo[i] > r || hi[i] < l) return;
            else if(lo[i] >= l && hi[i] <= r) {
                delta[i] += c;
                return;
            }

            Prop(i);
            Update(2 * i, l, r, c);
            Update(2 * i + 1, l , r, c);
            Set(i);
        }

        int Query (int i, int l, int r) {
            if(lo[i] > r || hi[i] < l) return INT_MAX;
            else if(lo[i] >= l && hi[i] <= r) {
                return st[i] + delta[i];
            }

            Prop(i);
            int a = Query (2 * i, l, r);
            int b = Query (2 * i + 1, l, r);
            Set(i);
            assert(delta[i] == 0);
            return min(a, b);
        }
};


int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	SegmentTree sg(5);
	for(int i = 0; i < 5; ++i) {
		sg.Update(i, i, v[i]);
	}
	
    return 0;
}

