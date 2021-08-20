#include <bits/stdc++.h>
using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while (t--) {

		int n, ops = 0;
		cin>>n;

		int curr = n, sqr = sqrt(n)+1;
		for(int i = n-1; i > 2; i--) {
               if(curr>5 && i == sqr) {
                    curr = sqr;
                    sqr = sqrt(curr)+1;
                    ops+=2;
               }
               else {
                    ops++;
               }
		}

		int currc = curr;
		while(curr>1) {
               curr=ceil((float)curr/2);
               ops++;
		}

		cout<<ops<<"\n";
		
		curr = n, sqr = sqrt(n)+1;
		for(int i = n-1; i > 2; i--) {
               if(curr>7 && i == sqr) {
                    cout<<curr<<" "<<i<<"\n";
                    cout<<curr<<" "<<i<<"\n";
                    curr = sqr;
                    sqr = sqrt(curr)+1;
               }
               else {
                    cout<<i<<" "<<curr<<"\n";
               }
		}

		currc = curr;
		while(curr>1) {
               cout<<currc<<" "<<2<<"\n";
               curr=ceil((float)curr/2);
		}
	}
}
