/*
ID: ujjwal.9
TASK: beads
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
// C++14

int main(){
	freopen("beads.in", "rt", stdin);
	freopen("beads.out", "w", stdout);
	
	int n;
	scanf("%d",&n);
	string s;
	cin >> s;
	
	vector<int> done(n + 1);
	
	auto Set = [&](int x) {
		return (x%n + n)%n;
	};
	
	auto Front = [&](int j, int ic) {
		j = Set(j);
		int res = 0;
		vector<int> tobe(n + 1);
		for(char ch : {'r', 'b'} ) {
			int cnt = 0;
			string t = s;
			for(char & c : t) if(c == 'w') c = ch;
			char p = t[j];
			vector<int> vis = done;
			for(int k = j; p == t[k] && !vis[k]; k = Set(k + ic)) {
				++cnt;
				vis[k] = 1;
				p = t[k];
			}
			if(cnt > res) {
				res = cnt;
				tobe = vis;
			}
		}
		done = tobe;
		return res;
	};
	
	int answer = 0;
	for(int i = 0; i < n; ++i){
		fill(done.begin(), done.end(), false);
		answer = max(answer, Front(i - 1, -1) + Front(i, 1));
	}
	printf("%d\n", answer);
	
	return 0;	
}
