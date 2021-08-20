#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Sequence is only possible if n is odd . Proof : Let n be odd . For all integers A =  0... n - 1. and B = 0... n - 1. if we sum the sequence we will either
// get x or n + x. in case if n is odd the this number is equal that exactly n/2 -> is < n and other > n . as n is the middle point.But there will not be
// any middle point in case of odd. Moreover the constructivness is that make all the even sequence i.e 0 , 2 , 4 , 6, 8.. and note that remainder of such
// is always a permutation because if let x = 2k > y . then 2k (mod y ) is always odd. and we have already covered the even sequence less than n. 

// ** Note ** in this constructivness also even n will not form permutation becuase one of the sum formed will be n itself that will make 0 to repeat twice. 

void solve(){
	int n;
	scanf("%d",&n);
	
	if( !(n & 1)) {
		puts("-1");
		return;
	}
	

	
	for(int x : {0, 1}){
		for(int i = 0; i < n; ++i){
			printf("%d ", i );
		}
		puts("");
	}
	
	for(int i = 0 ; i < n; ++i){
		printf("%d ", (i + i)%n);
	}
	
}

int main(){
	int tt;
	tt = 1;
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;	
}
