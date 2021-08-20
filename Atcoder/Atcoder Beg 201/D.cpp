#include "bits/stdc++.h"

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

using vi = vector<int>;
using vvi = vector<vi>;

const int OO  = (int)1e9;

void Hello() {
	function < void (int, int) > h = [&] (int a, int b) {
		printf("%d %d", &a, &, b);
	};
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector<string> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	
	vvi dp(n + 1, vi(m + 1, -1));
	
	auto Valid = [&] ( int i , int j) {
		if(i < 0 || j < 0 || j >= m || i >= n) return false;
		return true;
	};
	
	auto Cost = [&] (int i, int j) {
		if(v[i][j] == '+') return 1;
		else return -1;
	};
	
	function < int (int , int) > Brute = [&] (int i, int j) {
		if(i == n - 1 && j == m - 1) return Cost(i , j);
		int & ans = dp[i][j];
		if(ans != -1) return ans;
		
		ans = OO;
		if(Valid(i + 1, j)) {
			ans = min(ans, Brute(i + 1, j));
		}
		if(Valid(i , j + 1)) {
			ans = min(ans, Brute(i , j + 1));
		}
		return ans + Cost(i, j);
	};
	
	int answer = Brute(0, 0);
	debug() << owo(answer);
	
	return 0;
}
