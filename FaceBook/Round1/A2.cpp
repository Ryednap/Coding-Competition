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


constexpr int Mod = (int)1e9 + 7;
using i64 = int64_t;

i64 add (i64 a, i64 b) {
	a = ((a + b)%Mod + Mod)%Mod;
	return a;
}

i64 sub (i64  a, i64 b) {
	a = ((a - b)%Mod + Mod)%Mod;
	return a;
}

i64 mul (i64 a, i64 b) {
	a = ((a * b)%Mod + Mod)%Mod;
	return a;
}


void solve () {
	int n; cin >> n;
	std :: string s;
	cin >> s;


	vector<vector<int>> dp ( n + 1, vector<int> (2, -1));
	dp[n][0] = dp[n][1] = 0;
	for (int i = n - 1;i >= 0; --i) {

			if (s[i] == 'F') { 
				dp[i][0] = min (dp[i + 1][0], dp[i + 1][1] + 1);
				dp[i][1] = min (dp[i + 1][0] + 1, dp[i + 1][1]);
				
			} else if (s[i] == 'O') {
				dp[i][0] = min (dp[i + 1][1] + 1, dp[i + 1][0]);
				dp[i][1] = (int)1e9;
			} else if (s[i] == 'X') {
				dp[i][0] = (int)1e9;
				dp[i][1] = min (dp[i + 1][1], dp[i + 1][0] + 1);
			}
	}


	vector<int> v(n), p(n);
	map<int, int> mapper;
	for (int i = 0; i < n; ++i) {
		v[i] = min (dp[i][0], dp[i][1]);
		if (dp[i][0] == (int)1e9) dp[i][0] = dp[i][1];
		if (dp[i][1] == (int)1e9) dp[i][1] = dp[i][0];
		p[i] = max (dp[i][0], dp[i][1]);
		if (s[i] == 'F') mapper[p[i]]++;
	}

	i64 ans = 0;
	vector<i64> suff(n);
	suff[n - 1] = p[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		suff[i] = add(suff[i + 1], p[i]);
	}

	for (int i = 0; i < n - 1; ++i) {
		 if (s[i] == 'F') mapper[p[i]]--;
		 ans = add(ans, sub(mul(v[i], n - i - 1), suff[i + 1]));
		 ans = add(ans, mapper[v[i] + 1]);
	}
	cout << ans << "\n";
}


int main () {
    ios::sync_with_stdio(false);
    int qq; cin >> qq;
    for (int tt = 1; tt <= qq; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}


