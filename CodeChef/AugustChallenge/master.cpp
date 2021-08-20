#include <bits/stdc++.h>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)

ll lcm (ll a, ll b) {
	return (a * b) / std::__gcd(a, b);
}

struct Person {
	int charging;
	int leaving;
	int index;
	Person () {}
	Person (int a, int b, int c) :
		charging(a), leaving(b), index(c) {}
	bool operator > (Person & p) const {
		int a = leaving - charging;
		int b = p.leaving - p.charging;
		if (a == b)
			return charging < p.charging;
		return a < b;
	}	
};

void solve() {
	int n;
	scanf ("%d", &n);
	std::priority_queue<Person> q;
	std::vector<int> v;
	for (int i = 0; i < n; ++i) {
		scanf ("%d", &v[i]);
	}	
	for (int i = 0; i < n; ++i) {
		int x; scanf ("%d", &x);
		q.push (Person(v[i], x, i + 1));
	}

	int curr = 0;
	while (!q.empty()) {
		while (true) {
			Person p = q.top();
			if(p.leaving - p.charging >= 0)
				break;
			q.pop();
		}

	}
}

int main () {
	int qq;
	scanf ("%d", &qq);
	for (int tt = 1; tt <= qq; ++tt) {
		solve();
	}
	return 0;
}