#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

// Easy problem
// 2 min 26 sec reading 7 min coding 1 min debugging.

class UnionFind {
	public :
		UnionFind (int n) {
			n = n + 1;
			parent.resize(n);
			size.resize(n);
			for(int i = 0; i < n; ++i) {
				parent[i] = i;
				size[i] = 1;
			}
		}
		
		int Get (int a) {
			if(a == parent[a]) return a;
			else return parent[a] = Get(parent[a]);
		}
		
		bool Unite (int a, int b) {
			a = Get (a);
			b = Get (b);
			if( a != b) {
				if(size[a] > size[b]) swap(a, b);
				size[b] += size[a];
				parent[a] = b;
				return true;
			} else return false;
		}

	private :
		vector<int> parent;
		vector<int> size;
};

int main() {
	int qq;
	scanf("%d", &qq);
	while ( qq-- ) {
		int n;
		scanf("%d", &n);
		UnionFind uf (n);
		cin >> ws;
		string s;
		pair<int, int> ans;
		while (getline(cin,s) && s != "") {
	
			stringstream ss (s);
			string q;
			int a, b;
			ss >> q >> a >> b;
			if(q == "c") uf.Unite(a, b);
			else {
				a = uf.Get(a);
				b = uf.Get(b);
				if(a == b) ans.f++;
				else ans.s++;
			}
		}
		printf("%d,%d\n", ans.f, ans.s);
		if(qq) puts("");
	}
		
	return 0;
}
