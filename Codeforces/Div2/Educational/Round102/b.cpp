#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int gcd(int a, int b) { return b ? gcd(b, a%b) : a;}
int lcm(int a, int b) { return ( a * b ) / gcd(a, b); };

int main( ) {
	int qq;
	scanf("%d",&qq);
	while(qq --) {
		string s, t;
		cin >> s >> t;
		int n = (int)s.length();
		 int m = (int)t.length();
		if(m > n) {
			swap(m,n);
			string temp = s;
			s = t;
			t = temp;
		}
		
		int x = lcm(n,m);
		int a = x/n;
		int b = x/m;
		string p = "", q = "";
		for(int i = 0; i < a; ++i) p += s;
		for(int i = 0; i < b; ++i) q += t;
		if(p == q) puts(p.c_str());
		else puts("-1");
	}
	
	return 0;	
}
