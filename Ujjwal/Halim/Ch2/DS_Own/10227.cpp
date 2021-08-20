#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<set<int>> vs (n + 1);
		string s;
		cin >> ws;
		while ( getline(cin, s) && s != "") {
			stringstream ss(s);
			int a, b;
			ss >> a >> b;
			vs[a].insert(b);
		}
		
		set<set<int>> ans;
		for(int i = 1; i <= n; ++i) {
			ans.insert(vs[i]); // There was a small doubt whether the empty set is considered as unique or not
		}

		printf ("%d\n", (int)ans.size());
		if(qq) puts("");
	}
	return 0;
}
