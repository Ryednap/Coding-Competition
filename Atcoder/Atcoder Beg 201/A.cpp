#include "bits/stdc++.h"

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main() {
	int A[3];
	for(int i = 0;i < 3; ++i) {
		scanf("%d", &A[i]);
	}
	sort(A,A+3);
	bool ok = false;
	do {
		if(A[2] - A[1] == A[1] - A[0]) ok = true;
		
	} while(next_permutation(A,A+3));

	puts(ok ? "Yes" : "No");
	return 0;
}
