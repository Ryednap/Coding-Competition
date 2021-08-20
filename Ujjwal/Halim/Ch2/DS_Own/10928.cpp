#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Very easy problem As the graph is directed just output the out-deg is just the size of adj list.

int main() {
	int qq;
	scanf("%d", &qq);
	while ( qq-- ) {
		int n;
		scanf("%d", &n);
		vector<int> edges[n + 1];
		cin >> ws; // buffer clear;
		for(int i = 1; i <= n; ++i) {
			string s, p; getline(cin, s);
			stringstream ss(s);
			while (ss >> p) {
				edges[i].push_back( stoi(p) );
			}
		}
	
		vector<int> ans;
		int mini = (int)1e9;
		for(int i = 1; i <= n; ++i) {
			mini = std :: min( mini, (int)edges[i].size());
		}
		for(int i = 1; i <= n; ++i) {
			if( (int)edges[i].size() == mini) ans.push_back(i);
		}
		printf("%d", ans[0]);
		for (int i = 1; i < (int)ans.size(); ++i) {
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}
