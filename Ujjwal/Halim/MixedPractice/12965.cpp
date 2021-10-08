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

int main () {
	int tt; cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> p(n), c(m);
		for (auto & x : p) cin >> x;
		for (auto & x : c) cin >> x;

		sort (p.rbegin(), p.rend());
		sort (c.begin(), c.end());
		p.push_back(0);

		int ans = INT_MAX, num = INT_MAX;
		for (int i = 0; i < (int)p.size(); ++i) {
			int value = lower_bound(c.begin(), c.end(), p[i]) - c.begin();
			debug() << owo(ans) owo(value + i) owo(num) owo(p[i]);
			if (ans >= value + i) ans = value + i, num = p[i];
			
		}
		printf ("%d %d\n", (num == INT_MAX ? 0 : num), (ans == INT_MAX ? 0 :  ans));
	}
	return 0;
}