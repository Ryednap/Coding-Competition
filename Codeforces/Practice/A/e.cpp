#include <bits/stdc++.h>
using namespace std;

/*
 * This lengthy solution is the result of mis-information
 * There are only two direction's R and D
 * The C is only (n, m)
 * Means that each and every luggage would eventually either reach last row or coloumn 
 * So all the last row should have R and the last col shuould have D
 * 
 * 
 * My solution is based on the graph approach which can solve the general purpose problem where all the cliques should be connected
 * Complexity still O(n*m) both the case.
 * 22 min
 */

class DSU {
	public :
		DSU (int n) {
			parent.resize(n);
			size.assign(n, 1);
			for(int i = 0; i < n; ++i) {
				parent[i] = i;
			}
		}
		int Get(int i) {
			if(parent[i] == i) return i;
			else return parent[i] = Get(parent[i]);
		}
		void Unite(int a, int b) {
			a = Get(a);
			b = Get(b);
			if(a != b) {
				if(size[a] > size[b]) swap(a, b);
				parent[a] = b;
				size[b] += size[a];
			}
		}
		
		int Answer() {
			int ans = 0;
			for(int i = 1; i < (int)parent.size(); ++i) {
				if(parent[i] == i) ++ans;
			}
			if(ans) return ans - 1;
			else return ans;
		}
		
	private :
		vector<int> parent, size;
};

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, m;
		scanf("%d %d", &n, &m);
		DSU ob(n * m + 1);
		map<pair<int, int>, int> cor;
		int x = 1;
		string ar[n];
		for(int i = 0; i < n; ++i) {
			string s; cin >> s;
			ar[i] = s;
			for(int j = 0; j < m; ++j) {
				cor[{i, j}] = x++;
			}
		}
		assert(x == n * m + 1);
		auto Valid = [&] (auto p) {
			
			if(p.first >= n || p.second >= m || p.first < 0 || p.second < 0) return false;
			return true;
		};
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j){
				char ch = ar[i][j];
				pair<int, int> to;
				if(ch == 'D') to = {i + 1, j};
				if(ch == 'R') to = {i, j + 1};
				if(ch == 'C') to = {i, j};
				if(!Valid(to)) to = {i, j};
				ob.Unite(cor[{i,j}], cor[to]);
			}
		}
		printf("%d\n", ob.Answer());
	}
	return 0;	
}
