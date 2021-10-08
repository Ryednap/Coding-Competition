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

/*
	Lvl  Problem
	Recomened problem for retrieving path 
	Note the way we are storing all the possible path.

*/


const int OO = (int)1e9;
int main () {
	int n, m;
	while (scanf ("%d %d", &n, &m) != EOF) {
		int bh, of, yh, mkt;
		scanf ("%d %d %d %d", &bh, &of, &yh, &mkt);
		++n;
		vector<vector<int>> dp(n + 1, vector<int> (n + 1,  OO));
		vector<vector<int>> mat(n + 1, vector<int> (n + 1,  OO));
		for (int i = 0; i < n + 1; ++i) dp[i][i] = mat[i][i] = 0;
		for (int i = 0; i < m;  ++i) {
			int a, b, c;
			scanf ("%d %d %d", &a, &b, &c);
			mat[b][a] = mat[a][b] = dp[a][b] = dp[b][a] = c;
			
		}

		vector<vector<vector<int>>> par(n + 1, vector<vector<int>> (n + 1));
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0 ; j < n; ++j) {
					int maybe = dp[i][k] + dp[k][j];
					if (maybe < dp[i][j]) dp[i][j] = maybe, par[i][j] = vector<int> (1, k);
					else if (maybe == dp[i][j]) par[i][j].push_back(k);
				}
			}
		}
		dp = mat;

		auto Set = [&] (int ii) {
			debug() << owo(ii);
			for (int i = 0; i < n + 1; ++i) {
				dp[ii][i] = dp[i][ii] = OO; // unreachable point
			}
		};

		function < void (int, int) > gen = [&] (int i, int j) {
			if (i == -1 || j == -1) return;
			auto v = par[i][j];
			Set (i); Set(j);
			for (auto & k : v) {
				if (k != i && k != j) {
					gen (i, k);
					gen (k, j);
				}
			}
		};

		gen (bh, of);
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0 ; j < n; ++j) {
					int maybe = dp[i][k] + dp[k][j];
					if (maybe < dp[i][j]) dp[i][j] = maybe;
				}
			}
		}

		if (dp[yh][mkt] < OO) printf ("%d\n", dp[yh][mkt]);
		else puts ("MISSION IMPOSSIBLE.");
	}
	return 0;
}