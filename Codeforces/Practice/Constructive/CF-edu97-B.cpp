//You are given a string s of even length n. String s is binary, in other words, consists only of 0's and 1's.
//String s has exactly n2 zeroes and n2 ones (n is even).
//In one operation you can reverse any substring of s. A substring of a string is a contiguous subsequence of that string.
//What is the minimum number of operations you need to make string s alternating? A string is alternating if si≠si+1 for all i. There are two types of alternating strings in general: 01010101... or 10101010...


#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// For each consecutive same character we require 1 operation but that operation must involve the sequence of some other character. So answer is number
// of consecutive/2 (ceil) . This is true becuase number of blocks of 0's and 1's are same and if not then we can always trade one block for the border 0's
// or 1's respectively.

 
void solve(){
	int n;
	scanf("%d",&n);
	char str[n];
	scanf("%s",str);
 	
 	int count = 0;
 	for(int i = 0; i < n - 1; ++i){
		if(str[i] == str[i + 1]){
			++count;
		}
	}
	printf("%d\n",(count + 1)/2);
}
	
	
int main(){
	int tt;
	scanf("%d",&tt);
	//tt = 1;
	for(int _ = 1;_ <=tt;++_ ){
		solve();
	}
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}
