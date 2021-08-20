#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pii>;

#define f first
#define s second

int main() {
	set<string> s;
	for(int i = 0; i < 4; ++i) {
		string st;
		cin >> st;
		s.insert(st);
	}
	puts((int)s.size() == 4 ? "Yes" : "No");
	return 0;
}