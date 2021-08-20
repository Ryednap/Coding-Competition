#include <bits/stdc++.h>

using si = std :: string;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		si str;
		std :: cin >> str;
		const int n = (int)str.length();
		int l, r;
		l = r = str.find('a');
		bool ok = true;
		if(l == si :: npos) {
			ok = false;
		}
		for(char ch = 'b'; (ch < 'a' + n) && ok; ++ch) {
			int pos = str.find(ch);
			if(pos == si :: npos) ok = false;
			else if(pos == l - 1) --l;
			else if(pos == r + 1) ++r;
			else ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}