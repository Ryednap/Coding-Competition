#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using psii = pair<string, pair<int, int>>;
#define f first
#define s second

#define FOR(a, b) for(int a = b; a < 10; ++a)

int main() {
	int qq, tt = 0;
	scanf("%d",&qq);
	while (qq--) {
		psii player[10];
		for(int i = 0; i < 10; ++i) {
			string name;
			int a, d;
			cin >> name >> a >> d;
			player[i] = {name, {a, d}};
			
		}
		int totalAttack = 0, totalDefence = 0;
		vector<string> p, q;
		
		FOR(i, 0) FOR(j, i + 1) FOR(k, j + 1) FOR(l, k + 1) FOR(m, l + 1) {
			int attack = 0, defence = 0;
			vector<string> a, b;
			for(int x : {i, j, k, l, m}) {
				attack += player[x].s.f;
				a.push_back(player[x].f);
			}
			for(int x = 0; x < 10; ++x) {
				string name = player[x].f;
				if(find(a.begin(), a.end(), name) == a.end()) {
					defence += player[x].s.s;
					b.push_back(name);
				}
			}
			
			if(totalAttack == attack) {
				if(totalDefence == defence) {
					if(p > a) p = a, q = b;	
					
				} else if(totalDefence < defence) {
					totalDefence = defence;
					p = a, q = b;
				}
				
			} else if(totalAttack < attack) {
				totalAttack = attack;
				totalDefence = defence;
				p = a, q = b;
			}
		}
		printf("Case %d:\n", ++tt);
		sort(p.begin(), p.end());
		sort(q.begin(), q.end());
		for(auto x : {p, q}) {
			printf("(%s", x[0].c_str());
			for(int i = 1; i < 5; ++i) {
				printf(", %s", x[i].c_str());
			}
			puts(")");
		}
	}
			
			
	return 0;
}
