#include<bits/stdc++.h>
using namespace std;

int n;
const int nax = (int)2e5 + 10;
char s[nax];
int dp[nax][4];

map<char, int> m  = { {'R', 1}, {'B', 2}, {'G', 3} };


int Brute(int i, int j){
	if(i == n) return 0;
	int &ans = dp[i][j];
	if(ans != -1) return ans;
	
	if(m[s[i]] == j){
		int res = (int)1e9 + 10;
		for(int k = 1; k <= 3; ++k){
			if(k != j){
				res = min(res, Brute(i + 1, k) + 1);
			}
		}
		return ans = res;
	} else {
		return ans = Brute(i + 1, m[s[i]]);
	}
}

void Build(int i, int j){
	if(i == n) return;
	
	if(m[s[i]] == j) {
		int res = Brute(i , j);
		for(auto x : m) {
			auto [ch, k] = x;
			if(k != j && Brute(i + 1, k) + 1 == res) {
				printf("%c", ch);
				Build(i + 1, k);
				return;
			}
		}
		assert(false);
	} else {
		printf("%c", s[i]);
		Build(i + 1, m[s[i]]);
	}

}
	

int main(){
	scanf("%d",&n);
	scanf("%s", s);
	memset(dp, -1, sizeof(dp));
	int ans = Brute(0, 0);
	printf("%d\n", ans);
	Build(0,0);
	return 0;
	
}
