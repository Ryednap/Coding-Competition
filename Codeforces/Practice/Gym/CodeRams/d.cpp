#include <bits/stdc++.h>

using namespace std;

class DSU {
	public :
		DSU (int n) {
			parent.resize(n);
			size.assign(n, 1);
			positive.assign(n, 0);
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
			}
		}
		
		void Set (int a) {
			a = Get(a);
			positive[a] = 1;
		}
		
		vector<int>  Answer () {
			vector<int> ans;
			for(int i = 1; i < (int)parent.size(); ++i) {
				int p = Get(i);
				if(positive[p]) ans.push_back(i);
			}
			return ans;
		}
	private :
		vector<int> parent;
		vector<int> size, positive;
};

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	DSU dsu (n + 1);
	for(int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		for(int j = 1; j < k; ++j) {
			int y ; 
			scanf("%d", &y);
			dsu.Unite(x, y);
		}
	}
	
	int c;
	scanf("%d", &c);
	map<int, int> neg;
	for(int i = 0; i < c; ++i) {
		int x;
		scanf("%d",&x);
		dsu.Set(x);
		neg[x] = 1;
	}
	
	vector<int> v = dsu.Answer();
	vector<int> ans;
	for(auto x : v) {
		if(neg[x]) continue;
		ans.push_back(x);
	}
	
	printf("%d\n", (int)ans.size());
	for(auto x : ans) {
		printf("%d ", x);
	}
	
	return 0;
}
