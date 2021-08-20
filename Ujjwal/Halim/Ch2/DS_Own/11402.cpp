#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

class SegmentTree {
	public :
		SegmentTree (vector<int> & v) {
			const int n = (int)v.size();
			A = v;
			st.resize(4 * n);
			A.resize(4 * n);
			lo.resize(4 * n);
			hi.resize(4 * n);
			changes.resize(4 * n);
			Init(1, 0, n - 1);

		}
		
		void Update(int l, int r, int c) {
			Update(1, l, r, c);
		}
		int Query(int l, int r) {
			debug() << owo(st[1]);
			int x = Query(1, l, r);
			return x;
		}
		
	private :
		vector<pii> st;
		vector<int> A, lo, hi;
		vector<stack<int>> changes;
		

		pii Add (pii a, pii b) {
			return make_pair(a.f + b.f, a.s + b.s);
		}
		
		pii Get (int i) {
			stack<int> s = changes[i];
			pii ans = st[i];
			while (!s.empty()) {
				int c = s.top(); s.pop();
				if(c == 0) ans.s += ans.f, ans.f = 0;
				if(c == 1) ans.f += ans.s, ans.s = 0;
				if(c == 2) swap(ans.f, ans.s);
			}
			return ans;
		}
		
		void Set(int i) {
			st[i] = Add(Get(2 * i), Get(2 * i + 1));
		}
		
		void Prop(int i) {
			stack<int> & s = changes[i];
			while (!s.empty()) {
				int c = s.top(); s.pop();
				changes[2 * i].push(c);
				changes[2 * i + 1].push(c);
			}
		}
		
		void Init (int i, int l, int r) {
			lo[i] = l;
			hi[i] = r;
			if(l == r) {
				if(A[l]) st[i] = make_pair(0, 1);
				else st[i] = make_pair(1, 0);
				return ;
			}
			int mid = (l + r) >> 1;
			Init(2 * i, l, mid);
			Init(2 * i + 1, mid + 1, r);
			Set(i);
		}
		
		void Update(int i, int l, int r, int c) {
			 if(lo[i] > r || hi[i] < l) return;
			 if(lo[i] >= l && hi[i] <= r) {
				 changes[i].push(c);
				 return;
			 }
			 Prop(i);
			 Update(2 * i, l, r, c);
			 Update(2 * i + 1, l, r, c);
			 Set(i);
		}
		
		int Query(int i, int l, int r) {
			 if(lo[i] > r || hi[i] < l) return 0;
			 if(lo[i] >= l && hi[i] <= r) {
				 return Get(i).s;
			 }
			 Prop(i);
			 int a = Query(2 * i, l, r);
			 int b = Query(2 * i + 1, l, r);
			 Set(i);
			 assert(changes[i].size() == 0);
			 return a + b;
		}
};
			
		

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while ( qq-- ) {
		int m;
		scanf("%d", &m);
		string s;
		for (int i = 0 ; i < m; ++i) {
			int t; scanf("%d",&t);
			string str; cin >> str;
			for(int j = 0; j < t; ++j) {
				s += str;
			}
		}
		printf("Case %d:\n", ++tt);
		const int n = (int)s.length();
		vector<int> v(n);
		for(int i = 0; i < n; ++i) {
			v[i] = s[i] - '0';
		}
		SegmentTree sg (v);
		int q;
		scanf("%d", &q);
		while (q--) {
			string str;
			int l, r;
			cin >> str >> l >> r;
			if(str == "F") sg.Update(l, r, 0);
			else if(str == "E") sg.Update(l, r, 1);
			else if(str == "I") sg.Update(l, r, 2);
			else {
				int ans = sg.Query(l, r);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
