#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define f first
#define s second

class  CircularParking {
public:
	 long long park(int N, int A, int B, int C) {
		parent.resize(N);
		for (int i = 0; i < N; ++i) {
			parent[i] = i;
		}
		long long ans = 0;
		vector<bool> done(N);
		for (int i = 0; i < N; ++i) {
			int x =  ( i * i * A +  B * i + C) % N; // landed
			int y = get(x); // has to go
			assert (done[y] == false);
			done[y] = true; // for assertion
			ans += ((y - x) % N + N)%N; // total movement
			unite(y, get((y + 1)%N)); // mark to the right
		}
		return ans;
	}

public:
	int get (int a) {
		if (parent[a] == a)
			return a;
		return parent[a] = get(parent[a]);
	}
	void unite (int a, int b) {
		a = get(a);
		b = get(b);
		if (a != b) {
			parent[a] = b;
		}
	}

private:
	vi parent;
};

int main () {
	int a, b, c, d;
	scanf ("%d %d %d %d", &a, &b, &c, &d);
	CircularParking ob;
	auto ans = ob.park(a, b, c, d);
	cout << ans << endl;
	return 0;
}