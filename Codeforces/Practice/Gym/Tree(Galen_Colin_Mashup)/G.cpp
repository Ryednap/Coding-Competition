#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)2e5 + 10;
vector<int> edges[nax];
set<int> v[nax];
vector<int> fact(nax, -1);

void Sieve() {
	vector<bool> p(nax, true);
	p[0] = p[1] = false;
	for(int i = 2; i < nax; ++i) {
		if(p[i]) {
			fact[i] = i;
	
			for(int j  = 2; i * j < nax; ++j) {
				p[i * j] = false;
				if(fact[i * j] == -1) fact[i *j] = i ;
			}
		}
	}
}

void Factorize(int a, int b ) {
	while(a > 1) {
		int x = fact[a];
		assert(x != -1);
		v[x].insert(b);
		a /= x;
	}
}

int h[nax];
void Dfs0(int node, int par, int ht) {
	h[node] = ht;
	for(int child : edges[node]) {
		if(child != par) {
			Dfs0(child, node, ht + 1);
		}
	}
}

int main() {
	Sieve();
	int n;
	scanf("%d" , &n);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		Factorize(x, i);
	}
	
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d",&a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	int answer = 0;
	
	Dfs0(1,1, 0);
	auto cmp = [](const int & a, const int & b) {
		return h[a] < h[b];
	};
	
	for(int i = 2; i < nax; ++i) {
		if( (int)v[i].size() == 0) continue;
		vector<int> tree (v[i].begin() ,v[i].end());
		sort(tree.begin() , tree.end(), cmp);
		map<int, int> mark;
		for(int x : tree) mark[x] = true;
		
		function < int(int) > Dfs = [&](int node) {
			mark[node] = false;
			int x = 0;
			for(int child : edges[node]) {
				if(mark[child]) x = max(x, Dfs(child));
			}
			return x + 1;
		};
		
		for(int x : tree) {
			if(mark[x]) {
				vector<int> maybe;
				mark[x] = false;
				for(int c : edges[x]) {
					if(mark[c]) {
						maybe.push_back(Dfs(c));
					}
				}
				sort(maybe.rbegin() , maybe.rend());
				const int m = (int)maybe.size();
				int res = 1;
				for(int j = 0; j < min(2,m); ++j) res += maybe[j];
				answer = max(answer, res);
			}
		}
	}
		
	printf("%d\n", answer);
	return 0;
}
