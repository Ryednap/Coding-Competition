#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class UnionFind {
	public :
		UnionFind (int n) {
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
			a = Get(a);
			b = Get(b);
			if(a != b) {
				if(size[a] > size[b]) swap(a, b);
				size[b] += size[a];
				parent[a] = b;
				return true;
			} else return false;
		}
		
		int ans(int x) {
			return size[x];
		}
		
	private :
		vector< int> parent;
		vector<int> size;
};

int main() {
	
	int n, m;
	while ( scanf("%d %d", &n, &m) && n) { // note don't put n && m as m can be 0 whereas n must not be
		UnionFind uf (n + 1);
		for(int i = 0; i < m; ++i) {
			int k ; scanf("%d", &k);
			int a = -1;
			for(int j = 0; j < k; ++j) {
				int x; scanf("%d",&x);
				if(a == -1) a = x;
				uf.Unite(a,x);
			}
		}
		
		printf("%d\n", uf.ans(uf.Get(0)));
	}
	
	return 0;
}
