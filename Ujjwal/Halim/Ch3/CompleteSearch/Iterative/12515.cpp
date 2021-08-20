#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int OO = (int)1e6;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	string movie[n];
	for(int i = 0; i < n; ++i) {
		cin >> movie[i];
	}

	for(int _ = 0; _ < m; ++_) {
		string a;
		cin >> a;
		int answer = OO, pos = -1;
		for(int j = 0; j < n; ++j) {
			string b = movie[j];
			int here = OO;
			for(int k = 0; k < (int)b.length(); ++k) {
				string s = b.substr(k, (int)a.length());
				if((int)s.length() != (int)a.length()) break;
				int cost = 0;
				for(int i = 0; i < (int)a.length(); ++i) {
					if(s[i] != a[i]) ++cost;
				}
				here = min(here, cost);
			}
			if(answer > here) {
				answer = here;
				pos = j;
			}
		}
		printf("%d\n", pos + 1);
	}
				
	return 0;
}
