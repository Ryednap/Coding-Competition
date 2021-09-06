#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif




int main () {
	int q;
	scanf ("%d", &q);
	deque<int> a;
	set<pair<int, int>> b;

	bool ok = false;
	 int i = 0;
	while (q--) {
		int c;
		scanf ("%d", &c);
		if (c == 1) {
			int x; scanf("%d",&x);
			a.push_back(x);
		} else if (c == 2) {
			if (ok && b.empty()) ok = false;
			int x;
			if (ok) {
				x = b.begin()->first;
				b.erase(b.begin());
			} else {
				x = a.front();
				a.pop_front();
			}
			printf ("%d\n",x);
		} else {
			ok= true;
			while (!a.empty()) {
				int x = a.front(); a.pop_front();
				b.insert(pair<int, int> (x, i++));
			}
		}
	}
	return 0;
}