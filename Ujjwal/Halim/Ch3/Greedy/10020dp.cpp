#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

const int nax = 2000;
int dp[nax][nax];
vector<pii> arr;
const int OO = (int)1e6;
int n, m;

int Brute (int i, int j) {
	if(i == n) {
		if(j >= m) return 0;
		else return OO;
	}
	
	int & ans = dp[i][j];
	if(ans != -1) return ans;
	
	int a = Brute(i + 1, j), b = OO;
	if(arr[i].f <= j && arr[i].s >= j) {
		b = Brute(i + 1, arr[i].s) + 1;
	}
	
	return ans = min(a, b);
}

vector<pii> ans;

void Build(int i, int j) {
	if(i == n) {
		return;
	}

	int here = Brute(i, j);
	if(Brute(i + 1, j) == here) {
		Build(i + 1, j);
	
	} else {
		ans.push_back(arr[i]);
		Build(i + 1, arr[i].s);
	}
}
	

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		scanf("%d", &m);
		int l, r;
		arr = vector<pii> ();
		ans = vector<pii> ();
		while (scanf("%d %d", &l, &r)) {
			if(!l && !r) break;
			if(r >= 0) arr.emplace_back(l, r);
		}
		
		n = (int)arr.size();
		sort(arr.begin(), arr.end(), [](const pii & a, const pii & b) {
			if(a.f == b.f) return a.s > b.s;
			return a.f < b.f;
			});
			
		memset(dp, -1, sizeof(dp));
		int answer = Brute(0, 0);
		if(answer >= OO) puts("0");
		else {
			printf("%d\n", answer);
			Build(0, 0);
			sort(ans.begin(), ans.end());
			for(auto & p : ans) {
				printf("%d %d\n", p.f, p.s);
			}
		}
		if(qq) puts("");
	}
	return 0;
}
