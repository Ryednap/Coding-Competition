#include<bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * The maximum should be clear as more the value of n maximum is nC2.
 * The minimum is also similar but it requires a nice ceiling mod concept. If we try to minimise each group then they all should as minimum as possible.
 * Now the problem can be restated as given n and m divide n into m groups such each group division is non-decreasing. i.e 2 2 2 1 1 is valid but not
 * 1 2 1 2 2 . (**Source** Donald Knuth Mathematics : CH2). See the explanation also it is one of the most commonly used concept.
 */

long long nC2(int n){
	if(n == 0) return 0;
	return ( (long long)n * (n - 1))/2;
}

void solve(){
	int n , m;
	scanf("%d %d",&n,&m);
	
	long long Kmin , Kmax;		
	int r = n % m;
	
	Kmin = nC2( (n + m - 1)/m ) * r + nC2( n / m ) * (m - r);
	Kmax = nC2( n - m + 1 );
	printf("%lld %lld\n", Kmin, Kmax);
}

int main(){
	int tt;
	tt = 1;
	for(int i = 0; i < tt; ++i){
		solve();
	}	
	return 0;	
}
	
