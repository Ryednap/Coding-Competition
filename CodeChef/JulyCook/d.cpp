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
		 int n;
		 scanf("%d", &n);
		 map<int, int> mapper;
		 for(int i = 0; i < n; ++i) {
		 	int x; scanf("%d", &x);
		 	mapper[x]++;
		 }
		 int answer = 0;
		 for(auto p : mapper) {
			answer += min(p.s, p.f - 1);
			debug() << owo(p);
		 }
		 printf("%d\n", answer);
	}
	return 0;
}