#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
int n, m;
string cur , res;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		cin >> cur >> res;
		n = cur.size();
		m = res.size();
		bool ans = true;
		for (int start = 0 ; start <n; start++){
			for (int rsteps = 0 ; rsteps < n; rsteps++){
				int i = start;
				int j = 0;
				ans = true;
				int total = rsteps;
				while(i <n && total >= 0 && j < m){
					if (cur[i] != res[j]){
						ans = false;
						break;
					}
					i++;
					j++;
					total--;
				}
				if(! ans)
					continue;
				i-=2;
				while(i >= 0 && j <m){
					if (cur[i] != res[j]){
						ans = false;
						break;
					}
					i--;
					j++;
				}
				ans = (ans) && (j == m);
				if(ans)
					break;

			}
			if(ans)
				break;	
		}
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
