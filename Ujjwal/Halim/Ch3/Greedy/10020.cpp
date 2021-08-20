#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Mistakes

// The idea was correct but there was many flaws
// The idea was to sort the segments by the left and then by longest. 
// then based on the current req and possible next we will do the stuff


// Flaws :-
/*
 * 1:- What about if maybe doesnot overlaps the current one
 * 2:- The segment must overlap, i.e there should be atleast unit lenght intersection
 * 3:- Check the last segment 
 * 4:- Quit as soon the req becomes n
 * 5:- Proper meaurement.
 */

using pii = pair<int, int>;
#define f first
#define s second

int main() {
	int qq;
	scanf ("%d", &qq);
	while( qq--) {
		int n;
		scanf("%d", &n);
		int l, r;
		vector<pii> arr;
		while(scanf("%d %d", &l, &r)) {
			if(!l && !r) break;
			if(r >= 0) arr.emplace_back(l, r);
		}
		
		sort(arr.begin(), arr.end(), [](const pii & a, const pii & b) {
			
			if(a.f == b.f) return a.s > b.s;
			else return a.f < b.f;
		});
		
		int req = 0;
		pii maybe = {-1, -1};
		set<pii> ans;
		bool ok = true;

		for(int i = 0; i < (int)arr.size(); ++i) {
			if(req >= n) break;
			
			if(arr[i].f <= req && arr[i].s >= req) {
				if(arr[i].s > maybe.s) maybe = arr[i];
				
			} else if(arr[i].f > req) {
				if(maybe.s == -1 || maybe.f > req || maybe.s < req) ok = false;
				ans.insert(maybe);
				req = maybe.s;
				maybe = arr[i];
			}
		}
		
		if(req < n && maybe.f <= req && maybe.s >= req) {
			ans.insert(maybe);
			req = maybe.s + 1;
		}
		
		ok &= req >= n;
		if(!ok) puts("0");
		else {
			printf("%d\n", (int)ans.size());
			for(auto & p : ans) {
				printf("%d %d\n", p.f, p.s);
			}
		}
		if(qq) puts("");
	}
				
	return 0;
}
