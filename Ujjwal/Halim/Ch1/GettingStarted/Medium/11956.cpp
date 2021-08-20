#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// The question is wrong there's no operation at .

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while ( qq-- ) {
		string s;
		cin >> s;
		
		int arr[100] = {0};
		for(int i = 0, j = 0; i < (int)s.length(); ++i) {
			char c = s[i];
			if(c == '>') ++j;
			else if(c == '<') --j;
			
			j = (j % 100 + 100)%100;
			if(c == '+') arr[j]++;
			else if(c == '-') arr[j]--;
		}
		
		printf("Case %d:", ++tt);
		for(int i = 0; i < 100; ++i) {
			int x = arr[i];
			x = (x % 256 + 256)%256;
			stringstream ss;
			ss << hex << x;
			string ans = ss.str();
			transform (ans.begin(), ans.end(), ans.begin(), ::toupper);
			if((int)ans.length() == 1) printf(" 0%s", ans.c_str());
			else printf(" %s", ans.c_str());
		}
		puts("");
	}
	return 0;
}
