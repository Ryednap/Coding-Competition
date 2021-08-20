#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define "uj.h"
#endif

template<typename T> T Gcd(T a, T b) { return b ? Gcd(b, a%b) : a ;}
template<typename T, typename U> T Gcd(T a, T b, U & x, U & y){
	if(b){
		U x1, y1;
		T d = Gcd(b, a%b, x1, y1);
		x = y1;
		y = x1 - a/b * y1;
		return d;
		
	} else {
		x = 1, y = 0;
		return a;
	}
} 

extern const int Mod = (int)1e9 + 7;

template<typename T> static T Add(T a, T b){
	return ( ( a + b)%Mod + Mod)%Mod;
}
template<typename T> static void Add(T * a, T b){
	*a = Add(*a, b);
}
template<typename T> static T Mul(T a, T b){
	return ((static_cast<int64_t>(a) * b)%Mod + Mod)%Mod;
}
template<typename T> static void Mul(T * a, T b){
	*a = Mul(*a, b);
}
template<typename T> static T Sub(T a, T b){
	return ( ( a - b)%Mod + Mod)%Mod;
}
template<typename T> static void Sub(T * a, T b){
	*a = Sub(*a, b);
}

int modInv(int a){
	int x, y;
	int d = Gcd(a, Mod, x, y);
	if(d != 1){
		printf("Modular Inverse for %d doesnot exist. d = %d\n", a, d);
		assert(false);
	}
	return Add(x, 0);
}

int powMod(int a, int b){
	int res = 1;
	for(; b ; b >>= 1){
		if( b & 1) Mul(&res, a);
		Mul(&a, a);
	}
	return res;
}


void solve(){
	
	
	
}


int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;	
}
