#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define f first
#define s second

class   TripleEliminationTournament {
public:
	int countGames(int N, int G) {
		array<int, 3> ar =  {N, 0, 0};
		int ans = 0;
		bool ok = true;
		while (ok) {
			debug() << owo(ar);
			bool here = true;
			for (int i = 0; i < 3; ++i) {
				if (ar[i] != 0)
					here = false;
			}
				ok &= (!here);
				ok &= (ar[G] != 1);
				if (ar[0] & 1) {
					ar[0]--;
					ar[1]++;

				}
				if(ar[1] & 1) {
					if (ar[1] != 1 || G != 1) {
						ar[1]--;
						ar[2]++;
						
					}
				} if(ar[2] & 1) {
					
				}
				ans += (ar[0] / 2);
				ans += (ar[2] / 2);
				ans += (ar[1] / 2);
				int x = ar[0] >> 1;
				int y = ar[1] >> 1;
				ar[0] >>= 1;
				ar[1] >>= 1;
				ar[1] += x;
				ar[2] += y;
			}
			return ans;
		}

};


int main () {
	class TripleEliminationTournament ob;
	debug() << owo(ob.countGames(2, 0));
	return 0;
}