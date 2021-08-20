#include <bits/stdc++.h>

// unless all the points lies on a line which the point P in between A and B
// the answer is always gonna be eqaul to the manhattan distance

// Otherwise, we have to spend min of 2 costs per journey

using pii = std :: pair<int, int>;
#define f first
#define s second

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		pii a[3];
		for(int i = 0; i < 3; ++i) {
			scanf("%d %d", &a[i].f, &a[i].s);
		}
		int general = abs(a[0].f - a[1].f) + abs(a[0].s - a[1].s);

		if(a[0].f == a[1].f && a[0].f == a[2].f) {
			int mini = std :: min(a[0].s, a[1].s);
			int maxi = std :: max(a[0].s , a[1].s);
			if(a[2].s >= mini && a[2].s <= maxi)
				printf("%d\n", general + 2);
			else 
				printf("%d\n", general);

		} else if(a[0].s == a[1].s && a[0].s == a[2].s) {
			int mini = std :: min(a[0].f, a[1].f);
			int maxi = std :: max(a[0].f , a[1].f);
			if(a[2].f >= mini && a[2].f <= maxi)
				printf("%d\n", general + 2);
			else 
				printf("%d\n", general);

		} else {
			printf("%d\n", general);
		}
	}
	return 0;
}