#include "bits/stdc++.h"

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif




#define FOR(x) for(char x = '0'; x <= '9'; ++x)

int main() {
	string str;
	cin >> str;
	
	int count = 0;
	FOR(a) FOR(b) FOR(c) FOR(d) {
		set<char> s = {a, b, c, d};
		//debug() << owo(s);
		bool ok = true;
		for (int i = 0; i < (int)str.length(); ++i) {
			char ch = (char)(i + '0');
			if(str[i] == 'o' && s.find(ch) == s.end()) ok = false;
			if(str[i] == 'x' && s.find(ch) != s.end()) ok = false;
		}
		if(ok) ++count;
	}
	
	printf("%d\n", count);
	return 0;
}
