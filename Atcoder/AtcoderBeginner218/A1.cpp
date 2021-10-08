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


void solve () {
	int n; scanf ("%d", &n);
	std :: string s;
	cin >> s;


	vector<vector<int>> dp ( n + 1, vector<int> (3, -1));
	function < int (int , int) > hal = [&] ( int i, int j ) -> int {
		if (i == n) return 0;
		int & ans = dp[i][j];
		if (ans != -1) return ans;
		if (s[i] == 'F') return ans = min(hal (i + 1, 0) + j, hal(i + 1, 1) + !j);;
		int value = s[i] == 'O' ? 0 : 1;
		return ans = hal (i + 1, value) + value != j;
	};
	printf ("%d\n", hal(0, 2));
}

int main () {
	int qq;
	scanf ("%d",&qq);
	for (int tt = 1; tt <= qq; ++tt) {
		printf ("Case #%d: ", tt);
		solve();
	}
}
