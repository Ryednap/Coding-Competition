#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Through Union Find;

class UnionFind {
	public :
		UnionFind( int n ) {
			parent.resize(n);
			rank.resize(n);
			for( int i = 0; i < n; ++i) {
				parent[i] = i;
				rank[i] = 1;
			}
		}
		
		int Get (int i ) {
			if(parent[i] == i) return i;
			else return parent[i] = Get(parent[i]);
		}
		
		bool Unite (int a, int b) {
			a = Get(a);
			b = Get(b);
			if( a != b ) {
				if(rank[a] > rank[b]) swap(a, b);
				rank[b] += rank[a];
				parent[a] = b;
				return true;
			} else return false;
		}
		
		pair<int, int> Ans () {
			int a = 0, b = 0;

			for(int i = 0; i < (int)parent.size() ; ++i) {
				if(parent[i] == i) {
					if(rank[i] == 1) ++b;
					else ++a;
				}
			}
			return make_pair(a, b);
		}
		
	private :
		vector<int> parent;
		vector<int> rank;
};

int main() {
	int qq;
	scanf("%d", &qq);
	while ( qq-- ) {
		string s;
		vector<string> vs;
		while (cin >> s && s[0] != '*') {
			vs.push_back(s);
		}
		
		cin >> s;
		int n = 0;
		map<char, int> mapper;
		for(char ch : s) {
			if(isalpha(ch) && mapper.find(ch) == mapper.end()) {
				mapper[ch] = n ++;
			}
		}
		UnionFind uf(n);
		for( auto str : vs) {
			int a = mapper[str[1]];
			int b = mapper[str[3]];
			
			uf.Unite(a, b);
		}
		
		pair<int, int> ans = uf.Ans();
		printf("There are %d tree(s) and %d acorn(s).\n", ans.first, ans.second);
	}
	return 0;
}
