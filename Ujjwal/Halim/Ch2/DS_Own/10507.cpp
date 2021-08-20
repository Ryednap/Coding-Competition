#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// A bit of nice implementation problem;

// Problem faced. At first n is not the actual count we should subtract n by 3. 
// Note that validity depends on n to be 0 so at first i was missing this.
// Took more time because i kept thiking how to do this adhoc problem with UNION FIND

// Update : it seems the silly usage of the dsu is to figure out if the current element belongs to the active set or it (we can use an array why dsu ?).

const int nax = 100;
#define f first
#define s second

int main() {
	int n, m;
	while (scanf("%d %d",&n, &m) != EOF) {
		string ac; cin >> ac;
		map<char, vector<char>> edges;
		
		for(int i = 0 ; i < m; ++i) {
			string str; cin >> str;
			char a = str[0], b = str[1];
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		
		vector<char> used;
		map<char, bool> done;
		for(char ch : ac) {
			used.push_back(ch);
			done[ch] = true;
		}
		
		bool ok = true;
		int cnt = 0;
		n -= 3;
		while( n > 0 && ok ) {
			ok = false;
			map<char, int> count;
			for(char ch : used) {
				for(char child : edges[ch]) {
					count[child]++;
				}
			}
			
			for(auto p : count) {
				if(p.s >= 3 && !done[p.f]) {
					used.push_back(p.f);
					--n;
					ok = true;
					done[p.f] = true;
				}
			}
			++cnt;
		}
		
		if(n > 0) puts("THIS BRAIN NEVER WAKES UP");
		else printf("WAKE UP IN, %d, YEARS\n", cnt);
	}

	return 0;
}

