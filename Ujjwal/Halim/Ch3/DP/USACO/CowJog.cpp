/*
ID: adleon
TASK: cowjog
LANG: C++                 
*/

#include "bits/stdc++.h"
using namespace std;
//C++14

#ifdef LOCAL
#include "uj.h"
#endif

/*
	the concept used here is this that, If a cow that had started before some other cow eventually ends with more
	distance travelled then the other cow after T time then that cow has overtaken , meaning there was a moment when they
	shared same position, in that situtation both the cow cannot be on the same lane. 

	So you would have gussed by now that, all the cows in a lane must form an increasing sequence by the total distance
	travelled, i.e (initial_pos + veloctiy * Time). Hence the problem now converts to finding minimum number of increasing
	sequence which is precisely same as finding the longest non-decreasing subsequence.

*/

int main() {
	freopen("cowjog.in", "rt", stdin);
	freopen("cowjog.out", "w", stdout);

    int n, t;
    scanf("%d %d", &n, &t);
    vector<long long > dp;
    for(int i = 0; i < n; ++i) {
		long long x, s;
		scanf("%lld %lld", &x, &s);
		x = -(x + s * t);
		
		if(dp.empty() || x >= dp.back())
			dp.push_back(x);
		else {
			*(upper_bound(dp.begin(), dp.end(), x)) = x;
		}
	}
	printf("%d\n", (int)dp.size());
		
    return 0;
}
