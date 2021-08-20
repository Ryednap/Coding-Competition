#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Easy basic level problem
// 4 min of reading 10 min of coding 2 min of testing.

int main() {
	int qq;
	scanf("%d", &qq) ;
	while( qq-- ) {
		string s;
		vector<string> vs;
		while( cin >> s && s[0] != '*') {
			vs.push_back(s);
		}
		cin >> s;
		map<char, int> mapper;
		int i = 0;
		for(char c : s) {
			if(isalpha(c) && mapper.find(c) == mapper.end()) {
				mapper[c] = i++;
			}
		}

		vector<int> edges[i + 1];
		for(auto str : vs) {
			char a = str[1];
			char b = str[3];
			int u = mapper[a];
			int v = mapper[b];
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		
		pair<int, int> ans = {0, 0};
		int used[i + 1] = {0};
		function < int (int) > dfs = [&] (int node) {
			int cnt = 1;
			used[node] = true;
			for(auto child : edges[node]) {
				if(!used[child]) {
					cnt += dfs (child);
				}
			}
			return cnt;
		};
		
		for(int j = 0; j < i; ++j) {
			if(!used[j]) {
				int x = dfs(j);
				if(x > 1) ans.first ++;
				else ans.second ++;
			}
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n", ans.first, ans.second);
	}
		
	return 0;
}
