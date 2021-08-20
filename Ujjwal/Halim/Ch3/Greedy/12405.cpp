#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		char str[n + 1];
		scanf("%s", str);
		
		int ans = 0;
		int cnt = 0;
		
		for(int i = 0; i < n; ) {
			//debug() << owo(cnt) owo(ans);
			if(str[i] == '#') {
				if(cnt == 1 && i + 1 < n && str[i + 1] == '.') {
					++ans;
					i += 2;
					cnt = 0;
					
				} else {
					ans += (cnt != 0);
					cnt = 0;
					++i;
				}
				
			} else {
				++cnt;
				++i;
			}
			
			if(cnt == 3) {
				++ans;
				cnt = 0;
			}	
		}
		
		ans += (cnt!=0);	// earlier ans += cnt costed 2 WA
		printf("Case %d: %d\n", ++tt, ans);
	}	
	return 0;
}
