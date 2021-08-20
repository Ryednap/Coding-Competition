#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class UnionFind {
	public :
		UnionFind(int n) {
			parent.resize(n);
			size.assign(n, 1);
			for(int i = 0; i< n; ++i) {
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
			 if(a != b ) {
				 if(size[a] > size[b]) swap(a, b);
				 size[b] += size[a];
				 parent[a] = b;
			 }
		}
		int Ans() {
			int maxi = 0; 
			//debug() << owo(size);
			//debug() << owo(parent);
			for(auto x : size) {
				maxi = max(maxi, x);
			}
			return maxi;
		}
	private :
		vector<int> parent;
		vector<int> size;
};

int main() {
	
	int n, m;
	while( scanf("%d %d", &n, &m) ) {
		if(n == 0 && m == 0) break;
		map<string, int> mapper;
		UnionFind uf(n + 1);
		for(int i = 0; i < n; ++i) {
			string s; cin >> s;
			mapper[s] = i;
		}
		
		for(int i = 0; i < m; ++i) {
			string a, b;
			cin >> a >> b;
			uf.Unite(mapper[a], mapper[b]);
		}
		
		printf ("%d\n", uf.Ans());
	}
		
	return 0;
}
