#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
#define f first
#define s second



int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) { 
		set<int> s;
		for(int i = 0; i < 3; ++i) {
			int x;
			scanf("%d", &x);
			s.insert(x);
		}
		if((int)s.size() >= 2) puts("1");
		else puts("0");
	}
	return 0;
}