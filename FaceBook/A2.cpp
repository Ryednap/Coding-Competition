#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;
const int OO = (int)1e9;

int main () {
	int qq;
	scanf ("%d",&qq);
	for (int tt = 1; tt <= qq; ++tt)  {
		printf ("Case #%d: ", tt);
		std :: string s;
		std :: cin >> s;
		int dp[26][26], cnt[26];
		std :: set<char> st;
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				if (i == j) dp[i][j] = 0;
				else dp[i][j] = OO;
			}
		}
		memset(cnt, 0, sizeof(cnt));

		for (auto & ch : s) {
			cnt[ch - 'A']++;
			st.insert(ch);
		}
		int m; scanf ("%d",&m);
		while (m--) {
			std :: string ii; std :: cin >> ii;
			int u = ii[0] - 'A';
			int v = ii[1] - 'A';
			dp[u][v] = 1;
		}
		for (int k = 0; k < 26; ++k) {
			for (int i = 0; i < 26; ++i) {
				for (int j = 0; j < 26; ++j) {
					dp[i][j] = std :: min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}

		int ans = (int)1e9;
		for (int i = 0; i < 26; ++i) {
			int ansHere = 0;
			for (const char & ch : st) {
				int j = ch - 'A';
				if (dp[j][i] >= OO) {
					ansHere = OO;
					break;
				} else {
					ansHere += dp[j][i] * cnt[j];
				}
			}
			ans = std :: min(ans, ansHere);
		}
		printf ("%d\n", ans >= OO ? -1 : ans);
	}
}