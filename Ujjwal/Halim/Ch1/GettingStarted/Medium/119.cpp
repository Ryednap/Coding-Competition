#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf("%d",&n);
	while ( n ) {
		string names[n];
		for(int i = 0; i < n; ++i) {
			cin >> names[i];
		}
		map<string, int> ans;
			
		for(int i = 0; i < n; ++i) {
			string name; cin >> name;
			int amount, m; 
			scanf("%d %d", &amount, &m);
			if(m == 0) continue;
			int net = amount / m;
			ans[name] -= m * net;
			for (int j = 0; j < m; ++j) {
				string s; cin >> s;
				ans[s] += net;
			}
		}
		
		for(int i = 0; i < n; ++i) {
			printf("%s %d\n", names[i].c_str(), ans[names[i]]);
		}
		if(scanf("%d", &n) != EOF) puts("");
		else break;
	}
	return 0;
}
