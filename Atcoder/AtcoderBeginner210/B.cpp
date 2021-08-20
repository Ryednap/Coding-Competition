#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL 
#include "uj.h"
#endif 

using pii = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pii>;

#define f first
#define s second
#define sz(x) ((int)x.size())


int main() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	int last = -1;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '1') {
			last = i;
			break;
		}
	}	
	puts(last & 1 ? "Aoki" : "Takahashi");
	return 0;
}