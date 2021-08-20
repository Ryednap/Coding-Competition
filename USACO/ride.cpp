/*
ID: ujjwal.9
TASK: ride
LANG: C++                 
*/

#include<bits/stdc++.h>
using namespace std;
// C++14

const int mod = 47;
void Mul(int &a, int b){
	a = ( ( a * b)%mod + mod)%mod;
}




int main(){
	
	freopen("ride.in", "rt", stdin);
	freopen("ride.out", "w", stdout);
	
	string a, b;
	cin >> a >> b;
	
	int my = 1, your = 1;	
	for(char ch : a) {
		Mul(my, (ch - 'A' + 1));
	}
	for(char ch : b) {
		Mul(your, (ch - 'A' + 1));
	}
	puts(my == your ? "GO" : "STAY");
	return 0;
}
