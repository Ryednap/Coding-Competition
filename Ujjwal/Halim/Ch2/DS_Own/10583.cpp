#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class UnionFind {
	public :
		UnionFind (int n ) {
			parent.resize(n);
			size.resize(n);
			for(int i = 0; i< n; ++i) {
				parent[i] = i;
				size[i] = 1;
			}
		}
		
		int Get (int a ) {
			if(a == parent[a]) return a;
			else return parent[a] = Get(parent[a]);
		}
		
		bool Union (int a, int b) {
			a = Get(a);
			b = Get(b);
			if( a != b ) {
				if (size[a] > size[b]) swap(a,b);
				size[b] += size[a];
				parent[a] = b;
				return true;
			}
			else return false;
		}
		
		int Ans () {
			int cnt = 0;
			for(int i = 0; i < (int)parent.size(); ++i) {
				if(i == parent[i]) ++cnt;
			}
			return cnt;
		}
		
	private :
		vector<int> parent;
		vector<int> size;
};


int main() {
	int n, m;
	int tt = 0;
	while ( scanf("%d %d", &n, &m) ) {
		if(n == 0 && m == 0) break;
		UnionFind uf (n);
		for(int i = 0; i < m ; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			--a, --b;
			uf.Union(a, b);
		}
		
		printf("Case %d: %d\n", ++tt, uf.Ans());
	}
	return 0;
}

