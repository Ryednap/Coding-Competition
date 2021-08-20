#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
using psi = pair<string, pii>;
#define f first
#define s second

// O(10^8) :/ how come it passes the time limit. I wonder I have O(1) per query idea but that would be bit messy to code.

int main() {
	int qq;
	scanf("%d", &qq);
	while( qq--) {
		int n;
		scanf("%d", &n);
		psi data[n];
		for(int i = 0; i < n; ++i) {
			cin >> data[i].f >> data[i].s.f >> data[i].s.s;
		}
		
		int q; scanf("%d", &q);
		while (q--) {
			int p; scanf("%d", &p);
			vector<string> ans;
			for(int i = 0; i < n; ++i) {
				if(p >= data[i].s.f && p <= data[i].s.s) ans.push_back(data[i].f);
				if((int)ans.size() > 1) break;
			}
			if((int)ans.size() == 1) puts(ans[0].c_str());
			else puts("UNDETERMINED");
		}
		if(qq) puts("");
	}
	return 0;
}
