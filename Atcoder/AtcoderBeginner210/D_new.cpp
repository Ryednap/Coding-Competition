#include <bits/stdc++.h>

using ll = long long;
ll a[1005][1005], b[1005][1005];

template<class T>
T ckmin(T a, T b){
	return std :: min(a, b);
}

int main() {
	int n, m;
	ll c;
	scanf("%d %d %lld", &n, &m, &c);
	memset(b, 0x3f, sizeof(b));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%lld", &a[i][j]);

	ll answer = 1e18L;
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) {
			b[i][j] = ckmin(b[i][j - 1], b[i - 1][j]);
			answer = ckmin(answer, a[i][j] + b[i][j] + c * (i + j));
			b[i][j] = ckmin(b[i][j], a[i][j] - c * (i + j));
		}

	memset(b, 0x3f, sizeof(b));
	for(int i = 1; i <= n; ++i)
		for(int j = m; j > 0; --j) {
			b[i][j] = ckmin(b[i - 1][j], b[i][j + 1]);
			answer = ckmin(answer, a[i][j] + c * (i - j) + b[i][j]);
			b[i][j] = ckmin(b[i][j], a[i][j] + c * (j - i));
		}

	printf("%lld\n", answer);
}