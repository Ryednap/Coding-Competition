#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class UnionFind {
	public :
		UnionFind (int n) {
			parent.resize(n);
			size.assign(n, 1);
			for(int i = 0; i< n; ++i) {
				parent[i] = i;
			}
		}
		
		int Get(int a) {
			if(a == parent[a]) return a;
			else return parent[a] = Get(parent[a]);
		}
		
		bool Union (int a, int b) {
			a = Get(a);
			b = Get(b);
			
			if(a != b) {
				if(size[a] > size[b]) swap(a, b);
				size[b] += size[a];
				parent[a] = b;
				return true;
			} else return false;
		}
		
		int Ans () {
			int maxi = 0;
			for(int x : size) {
				maxi = max(maxi, x);
			}
			return maxi;
		}
		
	private :
		vector<int> parent;
		vector<int> size;
		
};

int main() {
	int qq;
	scanf("%d",&qq);
	while ( qq-- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		UnionFind uf(n);
		for(int i = 0 ; i < m; ++i) {
			 int a, b;
			 scanf("%d %d", &a, &b);
			 --a, --b;
			 uf.Union(a, b);
		}
		
		printf("%d\n", uf.Ans());
	}
		
	return 0;
}
