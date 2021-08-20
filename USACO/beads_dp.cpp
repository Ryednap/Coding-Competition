/*
ID: ujjwal.9
TASK: beads
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
// C++14

#ifdef LOCAL
#include "uj.h"
#endif

// How to frame this problem in terms of dp. Note that we can now compute for each range of the left and right what is the maximum . for this we are
// starting from 0 and ending to 2 * n. at 0 we have left = [0,0] and right = [1, 2n] , for 1 we have left = [0, 1] and right = [2, 2n] and so on like this
// this means that eventuall we will end up calculating all the potential answer that our ranges can offer. and this number of range is linear so our
// answer is linear.

const int nax = (int)770;
int main(){
	freopen("beads.in", "rt", stdin);
	freopen("beads.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	s = s + s;
	n = 2 * n;
	
	int l[nax][2], r[nax][2];
	l[0][0] = l[1][0] = 0;
	r[0][n] = r[1][n] = 0;
	
	for(int i = 1; i <= n; ++i) {
		if(s[i - 1] == 'r') {
			l[0][i] = l[0][i - 1] + 1;
			l[1][i] = 0;
		} else if(s[i - 1] == 'b') {
			l[0][i] = 0;
			l[1][i] = l[1][i - 1] + 1;
		} else {
			l[0][i] = l[0][i - 1] + 1;
			l[1][i] = l[1][i - 1] + 1;
		}
	}
	
	for(int i = n - 1; i >= 0; --i) {
		if(s[i] == 'r') {
			r[0][i] = r[0][i + 1] + 1;
			r[1][i] = 0;
		} else if(s[i] == 'b') {
			r[0][i] = 0;
			r[1][i] = r[1][i + 1] + 1;
		} else {
			r[0][i] = r[0][i + 1] + 1;
			r[1][i] = r[1][i + 1] + 1;
		}
	}
	
	int answer = 0;
	for(int i = 0; i <= 2*n; ++i) {
		answer = max(answer, max(l[0][i], l[1][i]) + max(r[0][i], r[1][i]));
	}
	printf("%d\n", answer);
	return 0;	
}
