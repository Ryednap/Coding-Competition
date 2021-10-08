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

using pii = pair<int, int>;
int main () {
	int a, b, tt = 0;
	while (scanf ("%d %d", &a, &b)) {
		if (!a && !b) break;
		const int n = 110;
		const int OO = (int)1e9;

		vector<vector<int>> dp(n, vector<int> (n, OO));
		dp[a][b] = 1;
		unordered_set<int> s;
				s.insert(a), s.insert(b);
		while (scanf ("%d %d", &a, &b)) {
			if (!a && !b) break;
			dp[a][b] = 1;
			s.insert(a), s.insert(b);
		}
		for (int i = 0; i < n; ++i) {
			dp[i][i] = 0;
		}

		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dp[i][j] = min (dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		double ans = 0;
		for (auto ii : s) {
			for (auto jj : s) {
				debug() <<  owo(ii) owo(jj) owo(dp[ii][jj]);
				ans += dp[ii][jj];
			}
		}

		ans /= (s.size() * s.size()) - s.size();
		printf ("Case %d: average length between pages = %.3f clicks\n", ++tt, ans);
	}	
	return 0;
}