#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

const double PI = acos(-1.0);

int main() {
	int n, m , qq;
	scanf("%d", &n);
	vector<pii> v(n);

	for(auto & p : v) {
		scanf("%d %d", &p.f, &p.s);
	}
	scanf("%d", &m);
	vector<array<int, 2>> u(m + 1);
	for(int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		if(x <= 2) {
			u[i][0] = x;
			u[i][1] = -1;
		} else {
			u[i][0] = x;
			scanf("%d", &u[i][1]);
		}
	}
	
	auto Rotate = [&](int ang, pii cor) {
		double theta = PI * ang / 180;
		int a = cos(theta);
		int b = sin (theta);
		int x = cor.f * a - cor.s * b;
		int y = cor.s * a + cor.f * b;
	
		return make_pair(x, y);
	};
	
	auto Translate_x = [] (pii p , pii cor) {
		int x = p.f + (p.s & 1 ? -cor.f : cor.f);
		int y = cor.s;
		return make_pair(x, y);
	};
	
	auto Translate_y = [](pii p , pii cor) {
		int x = cor.f;
		int y = p.f + (p.s & 1 ? -cor.s : cor.s);
		return make_pair(x, y);
	};
	
	scanf("%d", &qq);
	long long rot = 0;
	pii p = {0, 0};
	pii q = {0, 0};
	while( qq-- ) {
		debug() << owo(qq);
		int a, b;
		scanf("%d %d", &a, &b);
		debug() << owo(a) owo(b);
		array<int, 2> ar = u[a];
		debug() << owo(ar);
		if(ar[0] == 1) rot -= 90;
		else if(ar[0] == 2) rot += 90;
		else if(ar[0] == 3) {
			p.f = 2 * ar[1] - p.f;
			p.s++;
		} else if(ar[0] == 4) {
			q.f = 2 * ar[1] - q.f;
			q.s++;
		}
		
		pii ans = Translate_y(q, Translate_x(p, Rotate(rot, v[b-1])));
		printf("%d %d\n", ans.f, ans.s);
	}
	return 0;
}
	
