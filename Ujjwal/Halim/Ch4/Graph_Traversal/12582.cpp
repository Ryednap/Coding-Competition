#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*

T 000:23:07.259
T 000:23:06.890
T 000:05:28.089

Logic was clear
Faced problem in bit arithmetic
Think a clear impl. Before starting.

*/

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;

#define f first
#define s second

std::string s;
map<char, int> mapper;

int dfs (int i) {
	mapper[s[i]]++;
	int next = i + 1;
	while (next < (int)s.length() && s[next] != s[i]) {
		mapper[s[i]]++;
		next = dfs (next);
	}
	return next + 1;
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		std::cin >> s;
		mapper.clear();
		dfs (0);
		printf ("Case %d\n", tt);
		mapper[s[0]]--;
		for (auto p : mapper) {
			printf ("%c = %d\n", p.f, p.s);
		}
	}	
	return 0;
}