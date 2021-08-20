#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class SegmentTree {
	public :
		SegmentTree (vector<int> & v) {
			A = v;
			const int n = (int)v.size();
			st.resize(4 * n);
			hi.resize(4 * n);
			lo.resize(4 * n);
			Init(1, 0 , n - 1);
		}
		
		void Update(int p, int c) {
			 Update(1, p, c);
		}
		
		int Query (int l, int r) {
			return Query(1, l, r);
		}
		
	private :
		vector<int> A, st;
		vector<int> lo, hi; 
		
		int Init (int i, int l, int r) {
			lo[i] = l; 
			hi[i] = r;
			if(l == r) {
				return st[i] = A[l];
			} 
			
			int mid = (l + r) >> 1;
			int a = Init (2 * i, l, mid);
			int b = Init (2 * i + 1, mid + 1, r);
			return st[i] = a + b;
		}
		
		int Update (int i, int p, int c) {
			if(lo[i] > p || hi[i] < p) return st[i] ;
			if(lo[i] == hi[i]) {
				return st[i] = c;
			}
			
			int a = Update(2 * i, p, c);
			int b = Update(2 * i + 1, p, c);
			return st[i] = a + b;
		}
		
		int Query (int i, int l , int r ) {
			if(lo[i] > r || hi[i] < l) return 0;
			if(lo[i] >= l && hi[i] <= r) return st[i];
			
			int a = Query(2 * i, l, r);
			int b = Query(2 * i + 1, l, r);
			return a + b;
		}
};

int main() {
	int n, tt = 0;
	scanf("%d", &n);
	while ( n ) {
		vector<int> v(n);
		for(int & x : v) scanf("%d", &x);
		SegmentTree sg(v);
		string s;
		printf("Case %d:\n", ++tt);
		while (cin >> s && s != "END") {
			if(s == "M") {
				int l, r;
				scanf("%d %d", &l, &r);
				--l, --r;
				printf("%d\n", sg.Query (l, r));
			} else {
				int a, b;	
				scanf("%d %d", &a, &b);
				--a;
				sg.Update(a, b);
			}
		}
		scanf("%d", &n);
		if (n) puts("");
		else break;
	}
	return 0;
}
