#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

void Solve(){
	int n;
	scanf("%d", &n);
	char str[n];
	scanf("%s", str);
	
	int j = n - 1;
	for(; j >= 0 && str[j] == ')'; --j) {}
	
	puts(j + 1 < (n - j - 1) ? "Yes" : "No");
}

int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		Solve();
	}
	return 0;
}
