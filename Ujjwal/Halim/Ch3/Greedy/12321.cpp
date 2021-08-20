#include <bits/stdc++.h>

using pii = std::pair<int, int>;
#define f first
#define s second

int main() {
	int l, g;
	while (scanf("%d %d", &l, &g)) {
		if(!l && !g)
			break;

		pii arr[g];
		for(int i = 0; i < g; ++i) {
			int x, r;
			scanf("%d %d", &x, &r);
			arr[i] = pii(x - r, x + r);
		}

		sort(arr, arr + g, [&] (const pii & a, const pii & b) {
			if(a.f == b.f)
				return a.s > b.s;
			return a.f < b.f;
		});

		int req =0;
		pii maybe = {-1,-1};
		int ans = 0;
		for(int i = 0; i < g; ++i) {
			if(arr[i].f <= req && arr[i].s >= req) {
				if(maybe.s < arr[i].s)
					maybe = arr[i];
			} else if(arr[i].f > req) {
				++ans;
				req = maybe.s;
				if(req < arr[i].f) {
					ans = -1;
					break;
				}
				maybe = arr[i];
			}
		}

		if(req < l) {
			if(maybe.s < l) ans = -1;
			else ++ans;
		}
		
		if(ans == -1) puts("-1");
		else printf("%d\n", g - ans);		
	}
}