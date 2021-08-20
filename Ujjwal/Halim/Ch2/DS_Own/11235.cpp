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
			lo.resize(4 * n); hi.resize(4 * n);
			Init(1, 0, n - 1);
		}
		
		int Query (int l, int r) {
			if(l > r) return 0;
			return Query (1, l, r);
		}
	
	private :
		vector<int> st, A;
		vector<int> lo, hi;
	
	private :
		int Init (int i, int l , int r) {
			lo[i] = l;
			hi[i] = r;
			if(l == r) {
				st[i] = A[l];
				return st[i];
			}
			
			int mid = (l + r) >> 1;
			return st[i] = max(Init(2 * i, l, mid), Init(2 * i + 1, mid + 1, r));
		}
		
		int Query (int i, int l, int r) {
			if(lo[i] > r || hi[i] < l) return 0;
			if(lo[i] >= l && hi[i] <= r) return st[i];
			return max(Query(2 * i, l, r), Query(2 * i + 1, l, r));
		}
};
	
using ui = unordered_map < int, int >;


int main() {
	 int n;
	 while (scanf("%d", &n) && n) {
		 int qq;
		 scanf("%d", &qq);
		 ui cnt, first, last;
		 vector<int> freq(n), arr(n);
		 for(int & x : arr) {
			 scanf("%d", &x);
		 }
		 
		 auto Preprocess = [&] () {
				 for(int i = n - 1; i >= 0; --i) {
					int x = arr[i];
					cnt[x]++;
					first[x] = i;
				}

				for(int i = 0; i < n; ++i) {
					int x = arr[i];
					freq[i] = cnt[x];
					last[x] = i;
				}
		 };
		 
		 Preprocess();
		 SegmentTree sg(freq);
		 
		 auto Solve = [&] (int l, int r) {
				int a = arr[l];
				int b = arr[r];
				if(a == b) {
					return r - l + 1;
					
				} else {
					int lo = last[a];
					int hi = first[b];
					return max( {lo - l + 1, r - hi + 1, sg.Query(lo + 1, hi - 1) });
				}
		 };
		 
		 while ( qq-- ) {
			 int l, r;
			 scanf("%d %d", &l, &r);
			 --l, --r;
			 printf("%d\n", Solve(l, r));
		 }
	 }
	return 0;
}
