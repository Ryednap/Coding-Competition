#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n), b(m);
	for (int & x : a) {
		scanf ("%d", &x);
	}
	for ( int & x : b) { scanf ("%d", &x);}
	int curr = a[0];
	int other = min(
				find(a.begin(), a.end(), curr ^ 1) - a.begin(),
				find(a.rbegin(), a.rend(), curr ^ 1) - a.rbegin() + 1
			);
	if (other >= n) other = -1;

	int ans = 0, ok = 1, past = curr;
	for (int i = 0; i < m;  ++i) {
		 if (b[i] == curr) {
		 	ans += (past == b[i]) ? 1 : 2;
		 	past = b[i];
		 } else if (ok) {
		 	if (other == -1) {
		 		ans = -1;
		 		break;
		 	} else ans += other + 1;
		 	ok = false;
		 	past = b[i];
		 } else {
		 	ans += (past == b[i]) ? 1 : 2;
		 	past = b[i];
		 }
	}
	printf("%d\n",ans);
}