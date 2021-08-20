#include <bits/stdc++.h>
using namespace std;

bool F (auto a, auto b) {
	if(a == b) return true;
	else {
		 int n = (int)a.length();
		 int m = (int)b.length();
		if(n & 1 || m & 1) return false;
		n >>= 1; 
		m >>= 1;
		string a1 = a.substr(0, n), a2 = a.substr(n, n);
		string b1 = b.substr(0, m), b2 = b.substr(m, m);
		
		return (F(a1, b1) && F(a2, b2)) || (F(a1, b2) && F(a2, b1));
	}
}

const int nax = (int)2e3;
map<string, int> mapper;
int curr = 1;
int dp[nax][nax];

int Get(string & a) {
	if(mapper[a] != 0) return mapper[a];
	else return mapper[a] = curr++;
}

bool Brute (string a, string b) {
	if(a == b) return true;
	int i = Get(a);
	int j = Get(b);
	int & ans = dp[i][j];
	if(ans != -1) return ans;
	
	int n = (int)a.length();
	int m = (int)b.length();
	if(n & 1 || m & 1) return (ans = 0);
	n >>= 1;
	m >>= 1;
	string a1 = a.substr(0, n), a2 = a.substr(n, n);
	string b1 = b.substr(0, m), b2 = b.substr(m, m);
	return (ans = ((Brute(a1, b1) && Brute(a2, b2)) || (Brute(a1, b2) && Brute(a2, b1))));
}
	
int main() {
	string a, b;
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	bool ok = Brute(a, b);
	puts(ok ? "Yes" : "No");
	return 0;
}
