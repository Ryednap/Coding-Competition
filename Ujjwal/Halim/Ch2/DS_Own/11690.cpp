#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class UnionFind {
	public :
		UnionFind (int n, vector<int> & v) {
			parent.resize(n);
			size.assign(n , 1);
			cost = v;
			for(int i = 0; i < n; ++i) {
				parent[i] = i;
			}
		}
		
		int Get(int a) {
			if(parent[a] == a) return a;
			else return parent[a] = Get(parent[a]);
		}
		
		void Unite (int a, int b) {
			a = Get(a);
			b = Get(b);
			if(a != b) {
				if(size[a] > size[b]) swap(a, b);
				size[b] += size[a];
				parent[a] = b;
				cost[b] += cost[a];
			}
		}
		
		bool Valid () {
			//debug() << owo(cost);
			//debug() << owo(parent);
			for(int i = 0; i < (int)parent.size(); ++i) {
				if(i == parent[i] && cost[i] != 0) return false;
			}
			return true;
		}
	private :
		vector<int> parent;
		vector<int> size;
		vector<int> cost;
};

int main() {
	int qq;
	scanf("%d", &qq);
	while ( qq-- ) {
		int n, m;
		scanf("%d %d",&n, &m);
		vector<int> v(n);
		for(int & x : v) {
			scanf("%d", &x);
		}
		UnionFind uf(n, v);
		for(int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			uf.Unite(a, b);
		}
		
		bool ok = uf.Valid();
		puts(ok ? "POSSIBLE" : "IMPOSSIBLE");
	} 
		
	return 0;
}
