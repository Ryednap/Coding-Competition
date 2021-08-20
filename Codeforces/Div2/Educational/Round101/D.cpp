#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define F first
#define S second

/** Fun Fact For some people this was harder than C but for me it was even easier than A solved it in 23 min i guess
 **/
 
 /* The solution one. How i builded this solution. consider any integer x now it's very easier for this to just kill it's juniors in like n move but the
  * problem ? who is going to kill this guy in atmost 5 moves. (Not always true sometimes he can be way more powerful). Well if we try to minimise this
  * number we can see that we will go for some integer x to y (y < x) and as soon as we reach y , y kill's x in the most minimum possible move. and then
  * y goes from [y - 1, ... z] and so on. now the solution lies in picking the interval such that total move <= n + 5. At first i choose this to be like
  * [x .. x/2] means just half the current x. Now we have like total move = n - 1 - |num| + 2*|num| , where num is the number of points like x, y and so on
  * which is rougly like log(n). So total <= n - 1 + log(n). Now this fail after like 10^4 or like even less. So what's the best  move than log(n) points?
  * Note that we can similarly go to log3() and so on. Note that what ever be the case if (x > y) then y needs atleast 2 move to make x = 1. so what's
  * the largest number we can go from y to x. well it's exactly y * y . That's the whole idea. start from y = 2 make all the square points and do this
  * this is smaller than n + 5. it's like now log(sqrt(n)).
  */ 
 


int main(){
	int tt;
	scanf("%d", &tt);
	while(tt--){
		int n ;
		scanf("%d", &n);
		if(n == 3){
			puts("2");
			puts("3 2");
			puts("3 2");
		} else {
			vector<pii> ans;
			bool mark[n] = {false};
			for(long long i = 2; i < n; i *= i){
				mark[i] = true;
			}
			
			int curr = n;
			for(int i = n - 1; i >= 2; --i){
				if(mark[i]){
					ans.push_back({curr, i});
					ans.push_back({curr, i});
					curr = i;
				} else {
					ans.push_back({i, curr});
				}
			}
			int s = (int)ans.size();
			//printf("%d \n\n\n", s);
			assert(s <= n + 5);
			printf("%d\n", s);
			for(pii x : ans){
				printf("%d %d\n", x.F, x.S);
			}
		}
	}
	return 0;
}
