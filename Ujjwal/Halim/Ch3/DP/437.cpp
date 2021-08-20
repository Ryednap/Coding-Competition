#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int nax = (int)2e3;
const int OO = (int)1e9;
vector<array<int, 3>> v;
int n;
int dp[nax][nax];

int Brute(int i, int j) {
	if(i == n) return 0;
	
	int & ans = dp[i][j];
	if(ans != -1) return ans;
	
	if(v[j][0] > v[i][0] && v[j][1] > v[i][1]) ans = max(ans, Brute(i + 1, i) + v[i][2]);
	ans = max(ans, Brute(i + 1, j));
	
	return ans;
}
	
int main() {
	int N, tt = 0;
	while (scanf("%d", &N) && N) {
		v.push_back({OO, OO, OO});
		for(int i = 0; i < N; ++i) {
			array<int, 3> ar;
			for(int j = 0; j < 3; ++j) {
				scanf("%d", &ar[j]);
			}
			sort(ar.begin(), ar.end());
			do {
				v.push_back(ar);	
			} while (next_permutation(ar.begin(), ar.end()));
		}
		sort(v.begin(), v.end(), [](array<int, 3> &a, array<int, 3> & b){
			if(a[0] == b[0]) return a[1] > b[1];
			else return a[0] > b[0];
		});
		//debug() << owo(v);
		n = (int)v.size();
		memset(dp, -1, sizeof(dp));
		int answer = Brute(1, 0);
		
		printf("Case %d: maximum height = %d\n", ++tt, answer);
		v.clear();
	}
	
	return 0;
}
