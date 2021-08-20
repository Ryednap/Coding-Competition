#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif
using pii = pair<int, int>;
#define f first
#define s second

map<pii, int> rmq;
const int OO = (int)1e9 + 10;
const int nax = (int)1e5 + 10;
int arr[nax];
int n;

void Preprocess () {
    for(int i = 0 ; i < n; i += sqrt(n)) {
        int mini = OO;
        for(int j = i ; j < min(i + (int)sqrt(n), n); ++j) {
			debug() << owo(j) owo(i) owo(arr[j]);
            mini = min(mini, arr[j]);
        }
        rmq[{i, i + sqrt(n) - 1}] = mini;
    }
}

int Query (int l, int r) {
    int mini = OO;
    for(auto p : rmq) {
        int a = p.f.f;
        int b = p.f.s; // [a, b], [l, r]
        if(b < l) continue;
        if(r < a) break;
        if(a >= l && b <= r) {
            mini = min (mini, p.s);
        } else {
            for(int i = max(a, l) ; i <= min(b, r); ++i)  {
                mini = min(mini, arr[i]);
            }
        }
   }
    return mini;
}


int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	Preprocess();
	debug() << owo(rmq);
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int l, r;
		scanf("%d %d",&l, &r);
		printf("%d\n", Query(l, r));
	}
    return 0;
}
