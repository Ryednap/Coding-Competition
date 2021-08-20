#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Basic level problem
// 4 min 19 sec to read and think
// 8 min to code and debug

using pii = pair<int, int>;

#define f first
#define s second

struct Event {
	pii Period;
	int id;
	Event () {}
	Event (pii a, int b) : Period(a), id(b) {}
	bool operator < (Event e) const { // use the reverse comp for pq
		auto p = e.Period;
		int a = p.f * p.s;
		int b = Period.f * Period.s;
		if(a == b) return id > e.id;
		else return b > a;
	}
};

int main( ) {
	priority_queue< Event > pq;
	string s;
	while (cin >> s && s != "#") {
		int a, b;
		scanf("%d %d", &a, &b);
		pq.push(Event({b, 1}, a));
	}
	
	int k;
	scanf("%d",&k);
	for(int i = 0 ; i < k; ++i) {
		auto e = pq.top(); pq.pop();
		printf("%d\n", e.id);
		e.Period.s++;
		pq.push(e);
	}	
	
	return 0;	
}
