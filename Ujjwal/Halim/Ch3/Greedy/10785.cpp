#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	const string consnt = "JSBKTCLDMVNWFXGPYHQZR";
	const string vow = "AUEOI";
	
	int qq, tt = 0 ;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);	
		string name(n, ' '), first = "", second = "";;
		
		int a = 0, b = 0, j = 0, k = 0;
		for(int i = 0; i < n; ++i) {
			if(i & 1) {
				first += consnt[j];
				++a;
			} else {
				second += vow[k];	
				++b;
			}
			
			if(a == 5) a = 0, ++j;
			if(b == 21) b = 0, ++k;
		}
		sort(first.begin(), first.end());
		sort(second.begin(), second.end());
		j = 0, k = 0;
		for(int i = 0; i < n; ++i) {
			if(i & 1) {
				name[i] = first[j++];
			} else {
				name[i] = second[k++];
			}
		}
		printf("Case %d: %s\n", ++tt, name.c_str());
	}
	return 0;
}
