#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define owo(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


const int OO = (int)1e6;
int main ( ) {
	int n, m;
	scanf ("%d %d", &n, &m);
	unordered_map <char, int> mp;
	unordered_map <int, char> fp;
	vector<vector<int>> dp(32, vector<int> (32, OO));
	vector<vector<int>> par(32, vector<int> (32, -1));
	vector<vector<int>> len(32, vector<int> (32, OO));
	for (int i = 0, ii = 0; i < m; ++i) {
		string a, b;
		int cost;
		cin >> a >> b >> cost;
		char u = a[0], v = b[0];
		if (mp.find(u) == mp.end()) mp[u] = ii++;
		if (mp.find(v) == mp.end()) mp[v] = ii++;

		int p = mp[u], q = mp[v];
		fp[p] = u, fp[q] = v;
		dp[p][q] = dp[q][p] = cost;
		len[p][q] = len[q][p] = 1;
	}

	for (int i = 0; i < 32; ++i) dp[i][i] = 0, len[i][i] = 0;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int maybe = dp[i][k] + dp[k][j];
				int length = len[i][k] + len[k][j];
				if (maybe < dp[i][j]) {
					dp[i][j] = maybe;
					par[i][j] = k;
					len[i][j] = length;
				} else if (maybe == dp[i][j] && len[i][j] > length) {
					par[i][j] = k;
					len[i][j] = length;
				}
			}
		}
	}

	function < string (int, int) > gen = [&] (int i, int j){
		int k = par[i][j];
		if (k == -1) return string("");
		return gen(i, k) +  fp[k] + gen(k, j);
	};

	int qq; scanf ("%d", &qq);
	while (qq--){
		string a, b;
		cin >> a >> b;
		int u = mp[a[0]], v = mp[b[0]];
		debug() << owo(a) owo(b) owo(dp[u][v]) owo(len[u][v]);
		string ans = gen(u, v);
		printf ("%c", a[0]);
		for (char ch : ans) printf (" %c", ch);
		printf (" %c\n", b[0]);
	}
	return 0;
}