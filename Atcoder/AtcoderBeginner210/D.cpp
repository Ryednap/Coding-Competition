#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL 
#include "uj.h"
#endif 

using pii = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pii>;

#define f first
#define s second
#define sz(x) ((int)x.size())

using ll = long long;
const ll OO = 1e18L;

// Kind of sliding window on 2-d array if you can parition the manhattan distance on two cases
// if I am on (i, j) then I have 4 partition top-left, top-right, bottom-left, bottom-right.
// Note that we need to check each pair once. So if I iteraate from top - down and left-right manner on matrix
// then I need to only worry about bottom-left and bottom-right.

// In bottom-left the j co-cordinate is less and i is greater.
// In bottom-right both co-ordinates are greater.

// Now if you see the pattern for bottom-left then we are kinda adding previous columns one-by one
// Same can be said for bottom-right but when we reverse from bottom-top and right-left way.

int main() {
#define int long long
	int n, m, c;
	scanf("%lld %lld %lld", &n, &m, &c);

	int arr[n][m];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%lld", &arr[i][j]);
		}
	}

	vector<map<ll, int>>  A(m); // ++
	vector<map<ll, int>>  B(m); // +-


	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <m; ++j) {
			ll cost = arr[i][j] + c * (i - j);
			B[j][cost]++;
		}
	}


	ll answer = OO;
	for(int i = 0; i < n - 1; ++i) {

		for(int j = 0; j < m; ++j) {
			int here = arr[i][j] + c * (i - j);
			B[j][here]--;
			if(B[j][here] == 0) {
				B[j].erase(here);
			}
		}
		ll currMin = B[0].begin() -> first;
		for(int j = 1; j < m; ++j) {
			ll costHere = currMin + arr[i][j] + c * (-i + j);
			answer = min(answer, costHere);
			currMin = min(currMin, B[j].begin()->first);
		}
	}	

	for(int i = n - 1; i >= 0; --i) {
		ll currMin = OO;
		for(int j = m - 1; j >= 0; --j) {
			if(i != n - 1 || j != m -1) {
				if(i != n -1) currMin = min(currMin, A[j].begin() -> first);
				answer = min(answer, currMin + arr[i][j] - c * (i + j));
				//debug() << owo(currMin) owo(answer) owo(A);
			}
			ll cost = arr[i][j] + c * (i + j);
			currMin = min(currMin, cost);
			A[j][currMin]++;
		}
	}


	printf("%lld\n", answer);
	return 0;
}