#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Mistakes 

/* First implementation : Edges should be paired , and number of edges should be m (however in this i counted edges as number of 1's / 2 which is wrong)
 * Second implementation : Thought that it is saying for the graph to be connected so used Dfs to check , but still WA (don't know the reason)
 * Last implementation : Same as First but here when i saw solution found that it is asking unique edges should be m 
 */

int main() {
	int qq;
	scanf("%d", &qq);
	while ( qq-- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<int>> edges (m);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				int x; scanf("%d",&x);
				if(x) edges[j].push_back(i);
			}
		}

		bool ok = true;
		set<pair<int, int>> v;
		for(int i = 0; i < m; ++i) {
			const int x = (int)edges[i].size();
			if(x != 0 && x != 2) {
				ok = false;
				break;
			}
			if(x != 2) continue;
			int a = edges[i][0];
			int b = edges[i][1];
			if(a > b) swap(a, b);
			v.insert ( make_pair (a, b) );
		}
		
		ok &= (int)v.size() == m; // number of unique edges should be equal to the m;
		puts(ok ? "Yes" : "No");
		
	}
	return 0;
}

//3
//3 3
//1 1 0
//0 1 1
//1 0 1
//3 1
//1
//1
//0
//3 3
//1 1 0
//1 1 1
//1 0 0
