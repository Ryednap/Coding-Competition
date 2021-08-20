#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class SegmentTree {
	public : 
		SegmentTree (vector<int> & v) {
			const int n = (int)v.size();
			A = v;
			st.resize(4 * n);
			lo.resize(4 * n);
			hi.resize(4 * n);
			Init(1, 0, n - 1);
			//debug() << owo(st);
			//exit(0);
		}
		
		void Update (int p, int c) {
			Update (1, p, c);
		}
		
		int Query (int l, int r) {
			//debug() << owo(l) owo(r) owo(st);
			return Query (1, l, r);
		}

	private :
		vector<int> A, st;
		vector<int> lo, hi;
		
		int Get (int c) {
			if(c < 0 ) return -1;
			if(c > 0) return 1;
			return 0;
		}
		
		int Get (int a, int b) {
			if(a == -2) return b;
			if(b == -2) return a;
			int c = a * b;
			return Get(c);
		}
		
		int Init (int i, int l, int r) {
			lo[i] = l;
			hi[i] = r;
			if(l == r) {
				return st[i] = Get(A[l]);
			}
			
			int mid = (l + r) >> 1;
			int a = Init (2 * i, l, mid);
			int b = Init (2 * i + 1, mid + 1, r);
			return st[i] = Get(a, b);
		}
		
		int Update (int i, int p, int c) {
			if(lo[i] > p || hi[i] < p) return st[i];
			if(lo[i] == hi[i]) {
				assert(lo[i] == p);
				return st[i] = Get(c);
			}
			
			int a = Update(2 * i, p, c);
			int b = Update(2 * i + 1, p, c);
			return st[i] = Get(a, b);
		}
		
		int Query (int i, int l, int r) {
			if(lo[i] > r || hi[i] < l ) return -2;
			if(lo[i] >= l && hi[i] <= r) return st[i];
			int a = Query (2 * i , l, r);
			int b = Query (2 * i + 1, l, r);
			return Get(a, b);
		}
			
};

int main() {
	int n, qq;
	while ( scanf("%d %d", &n, &qq) != EOF ) {
		vector<int> v(n);
		for(int & x : v) {
			scanf("%d", &x);
		}
		SegmentTree sg (v);
		while ( qq-- ) {
			string c;
			cin >> c;
			if(c == "P") {
				int l, r;
				scanf("%d %d", &l, &r);
				--l, --r;
				int ans = sg.Query(l, r);
				printf("%s",ans < 0 ? "-" : ans > 0 ? "+" : "0");
			} else {
				int a, b;
				scanf("%d %d",&a, &b);
				--a;
				sg.Update(a, b);
			}
		}
		puts("");
	}
	return 0;
}
