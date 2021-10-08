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
	int tt; cin >> tt;
	while (tt--) {
		int n, m; cin >> n >> m;
		int ans = 0;
		bool fine = true;
		while (n != 1) {
			if (n / m == 0) {
				fine = false; break;
			}
			ans += (n / m);
			n = (n % m) + (n / m);
		}

		if (fine) printf ("%d\n",ans);
		else puts ("cannot do this");
	}
	return 0;
}