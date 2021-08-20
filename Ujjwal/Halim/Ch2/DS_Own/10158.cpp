#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Unable try later.

class UnionFind {
	public :
		UnionFind( int n ) {
			fsize.assign(n, 1);
			esize.assign(n, 1);
			Friend.resize(n);
			Enemy.resize(n);
			
			for(int i = 0; i < n; ++i) {
				Enemy[i] = i;
				Friend[i] = i;
			}
		}
		
		int Get(int a, vector<int> &v) {
			if(v[a] == a) return a;
			else return v[a] = Get(v[a], v);
		}
		
		void Helper (int a, int b, vector<int> & parent, vector<int> & size) {
				if(a == b) return;
				if(size[a] > size[b]) swap(a, b);
				size[b] += size[a];
				parent[a] = b;
		}
		
		bool SetFriend (int a, int b) {
			a = Get(a, Friend);
			b = Get(b, Friend);
			
			int u = Get(a, Enemy);
			int v = Get(b, Enemy);
			
			if(a == b) return true;
			if(u == v) return false;
			
			Helper(a, b, Friend, fsize);
			Helper(u, v, Enemy, esize);
			return true;
		}
		
		bool SetEnemy (int a, int b) {
			a = Get(a, Enemy);
			b = Get(b, Enemy);
			
			int u = Get(a, Friend);
			int v = Get(b, Friend);
			if(a == b) return true;
			if(u == v) return false;
			Helper(a, b, Enemy, esize);
			Helper(u, v, Friend, fsize);
			return true;
		}
		
		bool isEnemy (int a, int b) {
			a = Get(a, Enemy);
			b = Get(b, Enemy);
			return a == b;
		}
		
		bool isFriend (int a, int b) {
			a = Get(a, Friend);
			b = Get(b, Friend);
			return a == b;
		}
		
		
	private :
		vector<int> Friend, Enemy;
		vector<int> fsize, esize;
};
		

int main() {
	int n;
	scanf("%d", &n);
	UnionFind uf (n);
	
	int q, a, b;
	while (scanf("%d %d %d", &q, &a, &b)) {
		if(a == 0 && b == 0 && q == 0) break;
		bool res = true;
		if(q == 1) {
			 res = uf.SetFriend(a, b);
		} else if(q == 2) {
			 res = uf.SetEnemy(a, b);
		} else if(q == 3) {
			res = uf.isFriend(a, b);
		} else {
			res = uf.isEnemy(a, b);
		}

		if(q < 3 && !res) puts("-1");
		else if(q >= 3) puts(res ? "1" : "0");
	}
	return 0;
}
