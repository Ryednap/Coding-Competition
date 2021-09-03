#include <bits/stdc++.h>
using namespace std;

bool isvowel(char v) {
    return (0x208222>>(v&0x1f))&1;
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <=qq; ++tt) {
		printf ("Case #%d: ", tt);
		std :: string s ;
		std :: cin >> s;
		int cons = 0, vow = 0;
		vector<int> c(26), v(26);
		for (auto & ch : s) {
			if (isvowel(ch)) {
				vow++;
				v[ch - 'A']++;
			} else {
				cons++;
				c[ch - 'A']++;
			}
		}


		int a = *max_element(c.begin(), c.end());
		int b = *max_element(v.begin(), v.end());
		int ans = min(
			2 * (cons - a) + vow,
			2 * (vow - b) + cons
		);
		printf ("%d\n", ans);
	}
}